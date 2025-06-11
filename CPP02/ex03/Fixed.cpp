/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:36:41 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 18:36:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {}

Fixed::Fixed(const Fixed& copy) : fixed(copy.fixed) {}

Fixed::Fixed(const int overwrite) {
    this->fixed = overwrite << bit;
}

Fixed::Fixed(const float overwrite) {
    this->fixed = roundf(overwrite * (1 << bit));
}

Fixed& Fixed::operator=(const Fixed& copy) {
    this->fixed = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

float    Fixed::toFloat( void ) const {
    return (float)this->fixed / (1 << bit);
}

int    Fixed::toInt( void ) const {
    return this->fixed >> bit;
}

int     Fixed::getRawBits( void ) const {
    return this->fixed;
}

void    Fixed::setRawBits( int const raw ) {
    this->fixed = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool    Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool    Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool    Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool    Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool    Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool    Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed   Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed   Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed   Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() * other.getRawBits() >> bit);
    return result;
}

Fixed   Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() << bit) / other.getRawBits());
    return result;
}

Fixed&  Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return tmp;
}

Fixed&  Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed   Fixed::operator--(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}