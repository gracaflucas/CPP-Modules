#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string& str) {
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    return false;
}

static bool isIntLiteral(const std::string& str) {
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);
    if (*end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
        return true;
    return false;
}

static bool isFloatLiteral(const std::string& str) {
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    char* end;
    std::strtof(str.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
        return true;
    return false;
}

static bool isDoubleLiteral(const std::string& str) {
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    char* end;
    std::strtod(str.c_str(), &end);
    if (*end == '\0')
        return true;
    return false;
}

static bool isSpecialFloat(const std::string& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    return false;
}

static bool isSpecialDouble(const std::string& str) {
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    return false;
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    if (isCharLiteral(literal)) {
        char c = literal[1];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    if (isIntLiteral(literal)) {
        int i = std::atoi(literal.c_str());
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        std::cout << "char: ";
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    if (isSpecialFloat(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        double d = static_cast<double>(f);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        int i = static_cast<int>(f);
        char c = static_cast<char>(f);
        double d = static_cast<double>(f);

        std::cout << "char: ";
        if (std::isnan(f) || f < 0 || f > 127)
            std::cout << "impossible" << std::endl;
        else if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int: ";
        if (std::isnan(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << i << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    if (isSpecialDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        float f = static_cast<float>(d);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        float f = static_cast<float>(d);
        int i = static_cast<int>(d);
        char c = static_cast<char>(d);

        std::cout << "char: ";
        if (std::isnan(d) || d < 0 || d > 127)
            std::cout << "impossible" << std::endl;
        else if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int: ";
        if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << i << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    std::cout << "Invalid input." << std::endl;
}