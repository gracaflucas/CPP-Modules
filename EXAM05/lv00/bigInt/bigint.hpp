#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <algorithm>

class	bigint {
    private:
        std::string     _big;
    public:
        bigint() : _big("0") {};
        bigint(unsigned int value) : _big(std::to_string(value)) {};
        bigint(std::string value) : _big(value.empty() ? "0" : value) {};
        bigint(const bigint &other) : _big(other._big) {};
        ~bigint() {};
        bigint &operator=(const bigint &other);

        bigint operator+(const bigint &other) const;
        bigint &operator+=(const bigint &other);

        bigint &operator++();
        bigint operator++(int);

        bigint operator<<(unsigned int digits) const;
        bigint &operator<<=(unsigned int digits);
        bigint &operator>>=(const bigint &other);

        bool operator<(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator<=(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator!=(const bigint &other) const;

        const std::string &get_big() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &other);

#endif