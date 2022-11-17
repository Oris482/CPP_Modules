/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:08 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 15:41:07 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name) {
    std::cout << this->_name << " with " << this->_weapon.getType() << " constructed" << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << this->_name << " destructed" << std::endl;
}

void HumanA::attack(void) const {
    std::cout << this->_name << " attacked with their " << this->_weapon.getType() << std::endl;
}
