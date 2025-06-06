/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:36:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 18:36:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 fixed;
        static const int    bit = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed(const int overwrite);
        Fixed(const float overwrite);
        Fixed& operator=(const Fixed& copy);
        ~Fixed();
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;

        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;

        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        static  Fixed& min(Fixed& a, Fixed& b);
        static  const Fixed& min(const Fixed& a, const Fixed& b);
        static  Fixed& max(Fixed& a, Fixed& b);
        static  const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif