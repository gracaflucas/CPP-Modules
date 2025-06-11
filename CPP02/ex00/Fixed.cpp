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

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& copy) : fixed(copy.fixed) {
    std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called." << std::endl;
    this->fixed = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called." << std::endl;
}

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called." << std::endl;
    return this->fixed;
}

void    Fixed::setRawBits( int const raw ) {
    this->fixed = raw;
}