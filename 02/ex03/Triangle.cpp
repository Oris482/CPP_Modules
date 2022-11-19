/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:28:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 22:57:00 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Triangle.hpp"
#define MSG_NOT_TRIANGLE "It is not a triangle!"

Triangle::Triangle(void): _a(0, 0), _b(0, 0), _c(0, 0), _isTriangle(false), _area(0) {
    std::cout << MSG_NOT_TRIANGLE << std::endl;
}

Triangle::~Triangle(void) {}

Triangle::Triangle(const Triangle &src) {
    *this = src;
}

Triangle& Triangle::operator= (const Triangle &src) {
    this->_a = src._a;
    this->_b = src._b;
    this->_c = src._c;
    this->_isTriangle = src._isTriangle;
    this->_area = src._area;
    return *this;
}

Triangle::Triangle(const Point a, const Point b, const Point c): _a(a), _b(b), _c(c) {
    this->_isTriangle = isCanBeTriangle(a, b, c);
    if (this->_isTriangle) this->_area = this->getTriangleArea();
    else {
        std::cout << MSG_NOT_TRIANGLE << std::endl;
        this->_area = 0;
    }
}

void Triangle::printInfo(std::string name) const {
    if (!this->_isTriangle) {
        std::cout << MSG_NOT_TRIANGLE << std::endl;
        return ;
    }
    std::cout << name << " - ";
    this->_a.printPos("A");
    this->_b.printPos("B");
    this->_c.printPos("C");
    std::cout << std::endl;
}

Fixed Triangle::getTriangleArea(void) const {
    if (!this->_isTriangle) {
        std::cout << MSG_NOT_TRIANGLE << std::endl;
        return (Fixed(0));
    }
    return (Point::getVectorCrossProduct(this->_a, this->_b, this->_c).toAbs() / 2);
}

void Triangle::checkPointInside(Point &P) const {
    if (!this->_isTriangle) {
        std::cout << MSG_NOT_TRIANGLE << std::endl;
        return ;
    }
    if (Triangle::bsp(this->_a, this->_b, this->_c, P))
        std::cout << "TRUE: Point is inside of a triangle ABC" << std::endl;
    else
        std::cout << "FALSE: Point is outside of a triangle ABC" << std::endl;
}

bool Triangle::isCanBeTriangle(const Point &A, const Point &B, const Point &C) {
    if (Point::getVectorCrossProduct(A, B, C) == 0) return false;
    return true;
}

