/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:58:42 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 17:58:42 by marvin           ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif