/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 22:41:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Point.hpp"
#include "Triangle.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::~Point(void) {}

Point::Point(const Point &src) {
    *this = src;
}

Point& Point::operator= (const Point &src) {
    this->_x = src._x;
    this->_y = src._y;
    return *this;
}

Point::Point(const float x, const float y): _x(x), _y(y) {}

void Point::printPos(std::string name) const {
    std::cout << name << ": (" << this->_x << ", " << this->_y << ") ";
}

Fixed Point::getVectorCrossProduct(const Point &base, const Point &A, const Point &B) {
    return Fixed( ( (A._x - base._x) * (B._y - base._y) ) - ( (A._y - base._y) * (B._x - base._x) ) );
}
