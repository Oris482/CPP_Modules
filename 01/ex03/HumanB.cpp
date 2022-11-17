/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 15:41:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(void) {}

HumanB::HumanB(std::string name): _weapon(NULL), _name(name) {
    std::cout << this->_name << " constructed" << std::endl;
}

HumanB::~HumanB(void) {
    std::cout << this->_name << " destructed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack(void) const {
    if (this->_weapon != NULL)
        std::cout << this->_name << " attacked with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon!" << std::endl;
}
