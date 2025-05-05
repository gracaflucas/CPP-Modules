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

class Fixed {
    private:
        int                 fixed;
        static const int    bit = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        // copy assignment
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif