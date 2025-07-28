#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong Command Line Argument, try ./btc 'file'." << std::endl;
        return 1;
    }
    // try to open file, if not, std::cout << "Error: could not open file." << std::endl;
    // check if every line in the file is setted as "date | value"
    // check if the dates are real dates, else, std::cout << "Error: bad input => " << input << std::endl;
    // check values, if not positive, std::cout << "Error: not a positive number." << std::endl;
    // a valid value is either a float or positive interger, between 0 and 100
    // check the limit, else, std::cout << "Error: too large a number." << std::endl;

    // the output of each line is either the error, or date => value = updatedValue;
    // std::cout << date << " => " << value << " = " << updatedValue << std::endl;
    return 0;
}