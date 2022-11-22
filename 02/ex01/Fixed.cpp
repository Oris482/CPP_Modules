/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 18:37:58 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define MSG_CONSTRUCTOR " constructor called"
#define MSG_DESTRUCTOR "Destructor called"
#define MSG_OPERATOR " operator called"
#define MSG_MEM_FUNC " member function called"

Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << MSG_DESTRUCTOR << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(const int num): _fixedPointValue(num << _fractionalBits) {
    std::cout << "Int" << MSG_CONSTRUCTOR << std::endl;
}

Fixed::Fixed(const float num): _fixedPointValue((int)roundf(num * (1 << _fractionalBits))) {
    std::cout << "Float" << MSG_CONSTRUCTOR << std::endl;
}

const int& Fixed::getRawBits(void) const {
    // std::cout << "getRawBits" << MSG_MEM_FUNC << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits" << MSG_MEM_FUNC << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (((float)this->_fixedPointValue / (1 << _fractionalBits)));
}

int Fixed::toInt(void) const {
    return ((int)(this->_fixedPointValue >> _fractionalBits));
}

std::ostream& operator<< (std::ostream& os, const Fixed& target) {
    os << target.toFloat();
    return os;
}
