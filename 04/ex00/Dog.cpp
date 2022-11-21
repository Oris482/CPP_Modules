/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:49:55 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 22:58:00 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Dog" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

Dog::Dog(const Dog &src) {
    std::cout << "Dog" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Dog& Dog::operator= (const Dog &src) {
    std::cout << "Dog" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "meong-meong!" << std::endl;
}
