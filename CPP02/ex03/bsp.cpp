/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:35:25 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 18:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed triangleArea(Point const p1, Point const p2, Point const p3) {
    Fixed res = (p1.getX() * (p2.getY() - p3.getY())) +
                (p2.getX() * (p3.getY() - p1.getY())) +
                (p3.getX() * (p1.getY() - p2.getY()));
    if (res < Fixed(0))
        res = res * Fixed(-1);
    return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed area = triangleArea(a, b, c).toFloat();
    Fixed area1 = triangleArea(point, b, c).toFloat();
    Fixed area2 = triangleArea(a, point, c).toFloat();
    Fixed area3 = triangleArea(a, b, point).toFloat();

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;
    return (area == area1 + area2 + area3);
}