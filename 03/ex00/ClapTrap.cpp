/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:30 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/20 00:33:01 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#define MSG_CONSTRUCTOR " constructor called"
#define MSG_DESTRUCTOR " destructor called"
#define MSG_OPERATOR " operator called"

const std::string ClapTrap::unitType = "ClapTrap";

ClapTrap::ClapTrap(void): _name("undefined"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "Default " << ClapTrap::unitType << MSG_CONSTRUCTOR << std::endl;
    this->printMyStatus();
}

ClapTrap::~ClapTrap(void) {
    std::cout << this->_name << " " << ClapTrap::unitType << MSG_DESTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "Copy " << ClapTrap::unitType << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &src) {
    std::cout << "Copy assignment " << ClapTrap::unitType << MSG_OPERATOR << std::endl;
    this->_name = src._name;
    this->_hitPoint = src._hitPoint;
    this->_energyPoint = src._energyPoint;
    this->_attackDamage = src._attackDamage;
    this->printMyStatus();
    return *this;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << this->_name << " " << ClapTrap::unitType << MSG_CONSTRUCTOR << std::endl;
    this->printMyStatus();
}

void ClapTrap::printMyStatus(void) const {
    std::cout << "Name : " << this->_name;
    std::cout << " | ";
    std::cout << "HP : " << this->_hitPoint;
    std::cout << " | ";
    std::cout << "EP : " << this->_energyPoint;
    std::cout << " | ";
    std::cout << "AD : " << this->_attackDamage;
    std::cout << std::endl;
}

bool ClapTrap::checkCanAction(void) const {
    if (this->_hitPoint == 0) {
        std::cout << "HP is 0!" << std::endl;
        return false;
    } else if (this->_energyPoint == 0) {
        std::cout << "EP is 0!" << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target) {
    if (this->checkCanAction()) {
        this->_energyPoint -=1;
        std::cout << ClapTrap::unitType << " " << this->_name << " attacks " << target \
                    << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoint == 0) {
        std::cout << "HP is already 0!" << std::endl;
        return ;
    }
    if (this->_hitPoint <= amount) this->_hitPoint = 0;
    else this->_hitPoint -= amount;
    std::cout << ClapTrap::unitType << " " << this->_name << " takes " << amount << " points of damage" << std::endl;
    std::cout << ClapTrap::unitType << " " << this->_name << " HP : " << this->_hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->checkCanAction()) {
        this->_hitPoint += amount;
        this->_energyPoint -=1;
        std::cout << ClapTrap::unitType << " " << this->_name << " is repaired " << amount << " points of HP" << std::endl;
        std::cout << ClapTrap::unitType << " " << this->_name << " HP : " << this->_hitPoint << std::endl;
    }
}
