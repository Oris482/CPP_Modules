/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:38:56 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Point.hpp"

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

void Point::checkInsideOfTriangle(Point const A, Point const B, Point const C) const {
    std::cout << "------------------------------------------" << std::endl;
    A.printPos("A");
    B.printPos("B");
    C.printPos("C");
    this->printPos("Point");
    std::cout << std::endl;
    if (Point::bsp(A, B, C, *this))
        std::cout << "TRUE: Point is inside of a triangle ABC" << std::endl;
    else
        std::cout << "FALSE: Point is outside of a triangle ABC" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

Fixed Point::getVectorCrossProduct(const Point &base, const Point &A, const Point &B) {
    return Fixed( ( (A._x - base._x) * (B._y - base._y) ) - ( (A._y - base._y) * (B._x - base._x) ) );
}

bool Point::isCanBeTriangle(const Point &A, const Point &B, const Point &C) {
    if (getVectorCrossProduct(A, B, C) == 0) return false;
    return true;
}

Fixed Point::getTriangleArea(const Point &A, const Point &B, const Point &C) {
    if (isCanBeTriangle(A, B, C) == false) return (Fixed(0));
    // Fixed temp;

    // temp = ((A._x * B._y) + (B._x * C._y) + (C._x * A._y)) \
    //             - ((B._x * A._y) + (C._x * B._y) + (A._x * C._y));
    // return (temp.toAbs() / 2);
    return (getVectorCrossProduct(A, B, C).toAbs() / 2);
}
