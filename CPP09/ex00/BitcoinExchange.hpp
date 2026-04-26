#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <sstream>
#include <cctype>

class BitcoinExchange {
    private:
        std::map<std::string, double> _rates;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);
        bool    loadDatabase(const std::string& filename);
        bool    processInput(const std::string& filename);
        bool    isValidDate(const std::string& date);
        double  parseValueLine(const std::string& line, std::string& outDate);

        class NegativeValueException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class TooLargeValueException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif
