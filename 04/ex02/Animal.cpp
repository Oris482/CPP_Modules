/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:36:44 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:48:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(void): _type("undefined") {
    std::cout << "Animal" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Animal" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Animal& Animal::operator= (const Animal &src) {
    std::cout << "Animal" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    return *this;
}

Animal::Animal(const std::string type): _type(type) {
    std::cout << "Animal" << " " << "string" << MSG_CONSTRUCTOR << std::endl;
}

std::string Animal::getType(void) const {
    return this->_type;
}
