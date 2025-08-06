#ifndef RPN_HPP
# define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

class RPN {
    private:
        std::list<std::string> tokenize(const std::string& input);
        bool isOperator(const std::string& token);
        bool applyOperator(std::list<int>& stack, const std::string& op);
    public:
        RPN();
        RPN(const RPN& copy);
        ~RPN();

        RPN& operator=(const RPN& other);
        bool evaluate(const std::string& expression, int& result);

};

#endif