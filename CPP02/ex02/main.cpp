/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:42:51 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 11:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// void testComparisons() {
//     Fixed a(1.5f);
//     Fixed b(2.5f);
//     Fixed c(1.5f);

//     std::cout << "\n--- Comparison Tests ---" << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a <= c: " << (a <= c) << std::endl;
//     std::cout << "a >= c: " << (a >= c) << std::endl;
//     std::cout << "a == c: " << (a == c) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;
// }

// void testArithmetic() {
//     Fixed a(5.5f);
//     Fixed b(2);

//     std::cout << "\n--- Arithmetic Tests ---" << std::endl;
//     std::cout << "a + b = " << (a + b) << std::endl;
//     std::cout << "a - b = " << (a - b) << std::endl;
//     std::cout << "a * b = " << (a * b) << std::endl;
//     std::cout << "a / b = " << (a / b) << std::endl;

//     // Uncomment to test divide by zero (will likely crash)
//     // Fixed zero;
//     // std::cout << "a / 0 = " << (a / zero) << std::endl;
// }

// void testIncrementDecrement() {
//     Fixed a;

//     std::cout << "\n--- Increment/Decrement Tests ---" << std::endl;
//     std::cout << "Initial a: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "--a: " << --a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a--: " << a-- << std::endl;
//     std::cout << "a: " << a << std::endl;
// }

// void testMinMax() {
//     Fixed a(1.25f);
//     Fixed b(2.75f);
//     Fixed const c(3.5f);
//     Fixed const d(1.0f);

//     std::cout << "\n--- Min/Max Tests ---" << std::endl;
//     std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
//     std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
//     std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
//     std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
// }

// int main() {
//     testComparisons();
//     testArithmetic();
//     testIncrementDecrement();
//     testMinMax();
//     return 0;
// }