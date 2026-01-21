#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _rates(copy._rates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_rates = other._rates;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream input(filename.c_str());
    if (!input.is_open()) {
        std::cout << "Error: couldn't open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
            std::istringstream valStream(valueStr);
            double value;
            valStream >> value;
            _rates[date] = value;
        }
    }
    input.close();
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream input(filename.c_str());
    if (!input.is_open()) {
        std::cout << "Error: couldn't open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line)) {
        if (line.empty())
            continue;
        std::string date;
        try {
            double value = parseValueLine(line, date);
            std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
            if (it == _rates.end() || it->first != date) {
                if (it == _rates.begin()) {
                    std::cerr << "Error: no valid date found in database for " << date << std::endl;
                    continue;
                }
                --it;
            }
            double rate = it->second;
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
    input.close();
}

static std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;
    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;
    return s.substr(start, end - start);
}

double BitcoinExchange::parseValueLine(const std::string& line, std::string& outDate) {
    std::string trimmedLine = trim(line);
    size_t pipe = trimmedLine.find('|');
    if (pipe == std::string::npos) {
        throw std::runtime_error("Error: bad input => " + line);
    }
    std::string date = trim(trimmedLine.substr(0, pipe));
    std::string valueStr = trim(trimmedLine.substr(pipe + 1));
    if (!isValidDate(date)) {
        throw std::runtime_error("Error: bad input => " + date);
    }
    double value = 0;
    std::istringstream iss(valueStr);
    if (!(iss >> value) || !iss.eof()) {
        throw std::runtime_error("Error: invalid numeric value => " + valueStr);
    }
    if (value < 0) {
        throw NegativeValueException();
    }
    if (value > 1000) {
        throw TooLargeValueException();
    }
    outDate = date;
    return value;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    std::istringstream yss(date.substr(0, 4));
    std::istringstream mss(date.substr(5, 2));
    std::istringstream dss(date.substr(8, 2));
    if (!(yss >> year) || !(mss >> month) || !(dss >> day))
        return false;
    if (month < 1 || month > 12 || day < 1)
        return false;
    const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        maxDay = 29;
    return day <= maxDay;
}

const char* BitcoinExchange::NegativeValueException::what() const throw() {
    return "Error: not a positive number.";
}

const char* BitcoinExchange::TooLargeValueException::what() const throw() {
    return "Error: too large a number.";
}