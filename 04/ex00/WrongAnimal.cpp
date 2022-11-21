/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:05:15 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:11:06 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("undefined") {
    std::cout << "WrongAnimal" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    std::cout << "WrongAnimal" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal &src) {
    std::cout << "WrongAnimal" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    return *this;
}

WrongAnimal::WrongAnimal(const std::string type): _type(type) {
    std::cout << "WrongAnimal" << " " << "string" << MSG_CONSTRUCTOR << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "* UNDEFINED ANIMAL SOUND*" << std::endl;
}
