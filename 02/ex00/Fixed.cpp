/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 14:21:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define MSG_DEFALUT_CONSTRUCTOR "Default constructor called"
#define MSG_DEFAULT_DESTRUCTOR "Destructor called"
#define MSG_COPY_CONSTRUCTOR "Copy constructor called"
#define MSG_ASSIGNMENT_OPERATOR "Copy assignment operator called"

#define MSG_GET_FUNC "getRawBits member function called"
#define MSG_SET_FUNC "setRawBits member function called"

Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << MSG_DEFALUT_CONSTRUCTOR << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << MSG_DEFAULT_DESTRUCTOR << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << MSG_COPY_CONSTRUCTOR << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed &src) {
    std::cout << MSG_ASSIGNMENT_OPERATOR << std::endl;
    this->_fixedPointValue = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << MSG_GET_FUNC << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << MSG_SET_FUNC << std::endl;
    this->_fixedPointValue = raw;
}
