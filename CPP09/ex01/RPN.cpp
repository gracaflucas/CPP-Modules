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
        tokens.push_back(std::string(1, input[i]));
        ++i;
    }
    return tokens;
}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::applyOperator(std::stack<int>& stack, const std::string& op) {
    if (stack.size() < 2) return false;
    int right = stack.top(); stack.pop();
    int left = stack.top(); stack.pop();
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
    stack.push(res);
    return true;
}

bool RPN::evaluate(const std::string& expression, int& result) {
    std::list<std::string> tokens = tokenize(expression);
    std::stack<int> stack;
    for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        const std::string& token = *it;
        if (token.size() != 1)
            return false;
        if (std::isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else if (isOperator(token)) {
            if (!applyOperator(stack, token)) return false;
        } else {
            return false;
        }
    }
    if (stack.size() != 1) return false;
    result = stack.top();
    return true;
}