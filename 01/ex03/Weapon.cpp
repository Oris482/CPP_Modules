/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:07 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 15:31:55 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(const std::string &type): _type(type) {
    std::cout << "Weapon " << this->getType() << " constructed" << std::endl;
}

Weapon::~Weapon(void) {
    std::cout << "Weapon " << this->getType() << " destructed" << std::endl;
}

const std::string &Weapon::getType(void) const {
    return this->_type;
}

void Weapon::setType(const std::string &type) {
    this->_type = type;
}
