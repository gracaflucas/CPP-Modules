#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this = other;
    }
    return *this;
}