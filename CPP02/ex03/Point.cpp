/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:36:19 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 18:36:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}

Point& Point::operator=(const Point& copy) {
    (void)copy;
    return *this;
}

Point::~Point() {}

Fixed   Point::getX() const {
    return this->x;
}
Fixed   Point::getY() const {
    return this->y;
}