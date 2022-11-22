/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 18:32:45 by jaesjeon         ###   ########.fr       */
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
    // std::cout << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Fixed::~Fixed(void) {
    // std::cout << MSG_DESTRUCTOR << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    // std::cout << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Fixed& Fixed::operator= (const Fixed &src) {
    // std::cout << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(const int num): _fixedPointValue(num << _fractionalBits) {
    // std::cout << "Int" << MSG_CONSTRUCTOR << std::endl;
}

Fixed::Fixed(const float num): _fixedPointValue((int)roundf(num * (1 << _fractionalBits))) {
    // std::cout << "Float" << MSG_CONSTRUCTOR << std::endl;
}

bool Fixed::operator> (const Fixed &target) const {
    return (this->_fixedPointValue > target.getRawBits());
}

bool Fixed::operator>= (const Fixed &target) const {
    return (this->_fixedPointValue >= target.getRawBits());
}

bool Fixed::operator< (const Fixed &target) const {
    return (this->_fixedPointValue < target.getRawBits());
}

bool Fixed::operator<= (const Fixed &target) const {
    return (this->_fixedPointValue <= target.getRawBits());
}

bool Fixed::operator== (const Fixed &target) const {
    return (this->_fixedPointValue == target.getRawBits());
}

bool Fixed::operator!= (const Fixed &target) const {
    return (this->_fixedPointValue != target.getRawBits());
}

Fixed Fixed::operator+ (const Fixed &target) const {
    Fixed temp(this->toFloat() + target.toFloat());
    return temp;
}

Fixed Fixed::operator- (const Fixed &target) const {
    Fixed temp(this->toFloat() - target.toFloat());
    return temp;
}

Fixed Fixed::operator* (const Fixed &target) const {
    Fixed temp(this->toFloat() * target.toFloat());
    return temp;
}

Fixed Fixed::operator/ (const Fixed &target) const {
    Fixed temp(this->toFloat() / target.toFloat());
    return temp;
}

Fixed& Fixed::operator++(void) {
    ++(this->_fixedPointValue);
    return *this;
}

Fixed& Fixed::operator--(void) {
    --(this->_fixedPointValue);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(this->_fixedPointValue);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(this->_fixedPointValue);
    return temp;
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

float Fixed::getEpsilon(void) {
    return ((float)1 / (1 << _fractionalBits));
}

Fixed& Fixed::min(Fixed &A, Fixed &B) {
    std::cout << "reference parameters, return value" << std::endl;
    if (A.getRawBits() < B.getRawBits()) return A;
    return B;
}

const Fixed& Fixed::min(const Fixed &A, const Fixed &B) {
    std::cout << "const reference parameters, return value" << std::endl;
    if (A.getRawBits() < B.getRawBits()) return A;
    return B;
}

Fixed& Fixed::max(Fixed &A, Fixed &B) {
    std::cout << "reference parameters, return value" << std::endl;
    if (A.getRawBits() > B.getRawBits()) return A;
    return B;
}

const Fixed& Fixed::max(const Fixed &A, const Fixed &B) {
    std::cout << "const reference parameters, return value" << std::endl;
    if (A.getRawBits() > B.getRawBits()) return A;
    return B;
}

std::ostream& operator<< (std::ostream& os, const Fixed& target) {
    os << target.toFloat();
    return os;
}
