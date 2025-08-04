#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& copy) : _maxSize(copy._maxSize), _data(copy._data) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

void    Span::addNumber(int number) {
    if (_data.size() >= _maxSize) {
        throw std::runtime_error("Cannot add number: Span is full.");
    }
    _data.push_back(number);
}

int     Span::shortestSpan() const {
    if (_data.size() < 2) {
        throw std::runtime_error("Cannot find span: Not enough elements.");
    }
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int     Span::longestSpan() const {
    if (_data.size() < 2) {
        throw std::runtime_error("Cannot find span: Not enough elements.");
    }
    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());

    return maxVal - minVal;
}
