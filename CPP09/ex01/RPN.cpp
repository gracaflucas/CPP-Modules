#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
    (void)copy;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}

std::list<std::string> RPN::tokenize(const std::string& input) {
    std::list<std::string> tokens;
    size_t i = 0;
    while (i < input.size()) {
        if (std::isspace(input[i])) {
            ++i;
            continue;
        }
        if (std::isdigit(input[i])) {
            tokens.push_back(std::string(1, input[i]));
            ++i;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            tokens.push_back(std::string(1, input[i]));
            ++i;
        } else {
            tokens.push_back(std::string(1, input[i]));
            ++i;
        }
    }
    return tokens;
}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::applyOperator(std::list<int>& stack, const std::string& op) {
    if (stack.size() < 2) return false;
    int right = stack.back(); stack.pop_back();
    int left = stack.back(); stack.pop_back();
    int res = 0;
    if (op == "+")
        res = left + right;
    else if (op == "-")
        res = left - right;
    else if (op == "*")
        res = left * right;
    else if (op == "/") {
        if (right == 0)
            return false;
        res = left / right;
    } else
        return false;
    stack.push_back(res);
    return true;
}

bool RPN::evaluate(const std::string& expression, int& result) {
    std::list<std::string> tokens = tokenize(expression);
    std::list<int> stack;
    for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        const std::string& token = *it;
        if (token.size() != 1)
            return false;
        if (std::isdigit(token[0])) {
            int val = token[0] - '0';
            stack.push_back(val);
        } else if (isOperator(token)) {
            if (!applyOperator(stack, token)) return false;
        } else {
            return false;
        }
    }
    if (stack.size() != 1) return false;
    result = stack.back();
    return true;
}