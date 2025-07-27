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
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

static bool isSpecialFloat(const std::string& str) {
    return str == "-inff" || str == "+inff" || str == "nanf";
}

static bool isSpecialDouble(const std::string& str) {
    return str == "-inf" || str == "+inf" || str == "nan";
}

void ScalarConverter::convert(const std::string& literal) {
    double dVal;
    float fVal;
    int iVal;
    char cVal;

    if (isSpecialFloat(literal)) {
        fVal = std::strtof(literal.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << static_cast<double>(fVal) << std::endl;
        return;
    }
    if (isSpecialDouble(literal)) {
        dVal = std::strtod(literal.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(dVal) << "f" << std::endl;
        std::cout << "double: " << literal << std::endl; // nao tenho que printar o dval?
        return;
    }
    if (isCharLiteral(literal)) {
        cVal = literal[1];
        iVal = static_cast<int>(cVal);
        fVal = static_cast<float>(cVal);
        dVal = static_cast<double>(cVal);

        std::cout << "char: '" << cVal << "'" << std::endl;
        std::cout << "int: " << iVal << std::endl;
        std::cout << std::fixed << std::setprecision(1); // preciso usar fixed?
        std::cout << "float: " << fVal << "f" << std::endl;
        std::cout << "double: " << dVal << std::endl;
        return;
    }

    char* end; // aqui preciso descobrir o tipo, mudar para o tipo e fazer os casts, é um ultimo filtro
    errno = 0;
    dVal = std::strtod(literal.c_str(), &end);

    if (*end == 'f' && *(end + 1) == '\0') {
        fVal = static_cast<float>(dVal);
        iVal = static_cast<int>(fVal);
        cVal = static_cast<char>(fVal);
    }
    else if (*end == '\0') {
        fVal = static_cast<float>(dVal);
        iVal = static_cast<int>(dVal);
        cVal = static_cast<char>(dVal);
    }
    else {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    // prints caso passe de todos os edge cases
    std::cout << "char: ";
    if (std::isprint(cVal))
        std::cout << "'" << cVal << "'" << std::endl;
    else if (dVal >= 0 && dVal <= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (dVal < std::numeric_limits<int>::min() || dVal > std::numeric_limits<int>::max() || isnan(dVal))
        std::cout << "impossible" << std::endl;
    else
        std::cout << iVal << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << fVal << "f" << std::endl;
    std::cout << "double: " << dVal << std::endl;
}
