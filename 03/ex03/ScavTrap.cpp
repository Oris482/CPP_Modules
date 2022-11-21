/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:17:28 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 21:07:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap" << " " << this->_name << " " << MSG_DESTRUCTOR << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
    std::cout << "ScavTrap" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &src) {
    std::cout << "ScavTrap" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_name = src._name;
    this->_hitPoint = src._hitPoint;
    this->_energyPoint = src._energyPoint;
    this->_attackDamage = src._attackDamage;
    this->_gateKeeperMode = src._gateKeeperMode;
    return *this;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
    std::cout << "ScavTrap" << " " << this->_name << MSG_CONSTRUCTOR << std::endl;
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    this->_gateKeeperMode = false;
}

void ScavTrap::attack(const std::string &target) {
    if (this->checkCanAction() == false) return ;

    this->_energyPoint -=1;
    std::cout << "ScavTrap" << " " << this->_name << " attacks " << target \
                << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    if (this->checkCanAction() == false) return ;
  
    if (this->_gateKeeperMode) {
        std::cout << "ScavTrap" << " " << this->_name << " " << "is already in Gatekeeper mode" << std::endl;
        return ;
    }
    this->_gateKeeperMode = true;
    this->_energyPoint -= 1;
    std::cout << "ScavTrap" << " " << this->_name << " " << "is now in Gatekeeper mode" << std::endl;
}

