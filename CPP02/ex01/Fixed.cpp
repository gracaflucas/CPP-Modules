/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:58:34 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 17:58:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called." << std::endl;
    this->fixed = 0;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called." << std::endl;
    *this = copy;
}

Fixed::Fixed(const int overwrite) {
    std::cout << "Int constructor called." << std::endl;
    this->fixed = overwrite << bit;
}

Fixed::Fixed(const float overwrite) {
    std::cout << "Float constructor called." << std::endl;
    this->fixed = roundf(overwrite * (1 << bit));
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called." << std::endl;
    this->fixed = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called." << std::endl;
}

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