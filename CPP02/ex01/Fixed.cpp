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
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called." << std::endl;
}

// copy assignment

Fixed::~Fixed() {
    std::cout << "Destructor called." << std::endl;
}

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called." << std::endl;
}

void    Fixed::setRawBits( int const raw ) {
}

float   Fixed::toFloat( void ) const{}
int     Fixed::toInt( void ) const{}
Fixed::Fixed(const int raw){}
Fixed::Fixed(const float raw){}

// Anoverload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.