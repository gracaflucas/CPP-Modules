/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:35:58 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 18:35:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point vertexA(0, 0);
    Point edgeAB(5, 0);
    Point outside(10, 10);

    std::cout << std::boolalpha;
    std::cout << "Inside point: " << bsp(a, b, c, inside) << " (expected: true)" << std::endl;
    std::cout << "Vertex point: " << bsp(a, b, c, vertexA) << " (expected: false)" << std::endl;
    std::cout << "Edge point: " << bsp(a, b, c, edgeAB) << " (expected: false)" << std::endl;
    std::cout << "Outside point: " << bsp(a, b, c, outside) << " (expected: false)" << std::endl;

    return 0;
}