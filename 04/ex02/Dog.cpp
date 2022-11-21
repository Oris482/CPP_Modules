/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:49:55 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:46:11 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog(void) {
    std::cout << "Dog" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
    delete this->_brain;
}

Dog::Dog(const Dog &src) {
    std::cout << "Dog" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Dog& Dog::operator= (const Dog &src) {
    std::cout << "Dog" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    if (this->_brain) delete this->_brain;
    this->_brain = new Brain();
    *(this->_brain) = *src._brain;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "meong-meong!" << std::endl;
}

Brain& Dog::getBrain(void) const {
    return *this->_brain;
}
