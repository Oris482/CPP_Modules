/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:06:48 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 18:44:03 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap" << " " << this->_name << " " << MSG_DESTRUCTOR << std::endl;
    if (this->_highFiveCounter) delete this->_highFiveCounter;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
    std::cout << "FragTrap" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator= (const FragTrap &src) {
    std::cout << "FragTrap" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_name = src._name;
    this->_hitPoint = src._hitPoint;
    this->_energyPoint = src._energyPoint;
    this->_attackDamage = src._attackDamage;
    if (this->_highFiveCounter) delete this->_highFiveCounter;
    this->_highFiveCounter = new unsigned int;
    *this->_highFiveCounter = *src._highFiveCounter;
    return *this;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap" << " " << this->_name << MSG_CONSTRUCTOR << std::endl;
    this->_highFiveCounter = new unsigned int;
    *this->_highFiveCounter = 0;
}

void FragTrap::attack(const std::string &target) {
    if (this->checkCanAction()) {
        this->_energyPoint -=1;
        std::cout << "FragTrap" << " " << this->_name << " attacks " << target \
                    << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    if (*this->_highFiveCounter == UINT_MAX) {
        std::cout << "FragTrap" << " " << this->_name << " can't no more highfives" << std::endl;
        return ;
    }
    (*this->_highFiveCounter)++;
    std::cout << "FragTrap" << " " << this->_name << " highifives with guys! (total: " \
                    << this->getHighFiveCount() << " times)" << std::endl;
}

unsigned int FragTrap::getHighFiveCount(void) const {
    return *this->_highFiveCounter;
}
