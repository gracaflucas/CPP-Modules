#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <stdexcept>

class Span {
    private:
        unsigned int        _maxSize;
        std::vector<int>    _data;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        ~Span();
        Span& operator=(const Span& other);

        void    addNumber(int number);
        int     shortestSpan() const;
        int     longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end) {
            if (_data.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("Cannot add range: Span is full.");
            _data.insert(_data.end(), begin, end);
        }
};

#endif