#include "bigint.hpp"

bigint &bigint::operator=(const bigint &other) {
    if (this != &other) {
        _big = other._big;
    }
    return *this;
}

bigint &bigint::operator+=(const bigint &other) {
    int carry = 0;
    int i = _big.size() - 1;
    int j = other._big.size() - 1;
    std::string result;
    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? _big[i] - '0' : 0;
        int y = j >= 0 ? other._big[j] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
        --i;
        --j;
    }
    std::reverse(result.begin(), result.end());
    _big = result;
    return *this;
}

bigint bigint::operator+(const bigint &other) const {
    bigint copy(*this);
    copy += other;
    return copy;
}

bigint &bigint::operator++() {
    bigint one(1);
    *this += one;
    return *this;
}
bigint bigint::operator++(int) {
    bigint tmp = *this;
    bigint one(1);
    *this += one;
    return tmp;
}

bigint &bigint::operator<<=(unsigned int digits) {
    if (_big != "0")
        _big.append(digits, '0');
    return *this;
}

bigint bigint::operator<<(unsigned int digits) const {
    bigint copy(*this);
    copy <<= digits;
    return copy;
}

bigint &bigint::operator>>=(const bigint &other) {
    const unsigned int size = _big.size();
    const unsigned long amount = std::atol(other._big.c_str());

    if (size >= amount) {
        _big.erase(size - amount);
    }
    else {
        _big = "0";
    }
    return *this;
}

bool bigint::operator<(const bigint &other) const {
    if (_big.size() != other._big.size())
        return _big.size() < other._big.size()
    return _big < other._big;
}

bool bigint::operator>(const bigint &other) const {return (other < *this);}

bool bigint::operator<=(const bigint &other) const {return !(*this > other);}

bool bigint::operator>=(const bigint &other) const {return !(*this < other);}

bool bigint::operator==(const bigint &other) const {return (_big == other._big);}

bool bigint::operator!=(const bigint &other) const {return (_big != other._big);}

const std::string &bigint::get_big() const {
    return _big;
}

std::ostream &operator<<(std::ostream &os, const bigint &other) {
    os << other.get_big();
    return os;
}