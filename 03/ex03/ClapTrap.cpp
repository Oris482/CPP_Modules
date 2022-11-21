/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:30 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 18:42:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap" << " " << this->_name << " " << MSG_DESTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "ClapTrap" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &src) {
    std::cout << "ClapTrap" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_name = src._name;
    this->_hitPoint = src._hitPoint;
    this->_energyPoint = src._energyPoint;
    this->_attackDamage = src._attackDamage;
    return *this;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap" << " " << this->_name << MSG_CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoint, \
                    unsigned int energyPoint, unsigned int attackDamage): _name(name), _hitPoint(hitPoint), \
                                                                            _energyPoint(energyPoint), _attackDamage(attackDamage) {
    std::cout << "ClapTrap" << " " << this->_name << MSG_CONSTRUCTOR << std::endl;

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
        std::cout << "ClapTrap" << " " << this->_name << " attacks " << target \
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
    std::cout << "ClapTrap" << " " << this->_name << " takes " << amount << " points of damage" << std::endl;
    std::cout << "ClapTrap" << " " << this->_name << " HP : " << this->_hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->checkCanAction()) {
        this->_hitPoint += amount;
        this->_energyPoint -=1;
        std::cout << "ClapTrap" << " " << this->_name << " is repaired " << amount << " points of HP" << std::endl;
        std::cout << "ClapTrap" << " " << this->_name << " HP : " << this->_hitPoint << std::endl;
    }
}
