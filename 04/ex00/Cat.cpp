/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:01:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:02:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
    std::cout << "Cat" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

Cat::Cat(const Cat &src) {
    std::cout << "Cat" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Cat& Cat::operator= (const Cat &src) {
    std::cout << "Cat" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "ya-ong" << std::endl;
}
