#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>     // for isnan, isinf
#include <cstdlib>   // for strtol, strtod
#include <iomanip>   // for std::fixed, std::setprecision
#include <iostream>
#include <limits>
#include <string>


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& literal);
};

#endif
