/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:07:35 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:08:29 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
    std::cout << "WrongCat" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) {
    std::cout << "WrongCat" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator= (const WrongCat &src) {
    std::cout << "WrongCat" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_type = src._type;
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << "ya-ong" << std::endl;
}
