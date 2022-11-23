/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:02:24 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/23 12:18:32 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap" << " " << this->_name << " " << MSG_DESTRUCTOR << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), FragTrap(src), ScavTrap(src) {
    std::cout << "DiamondTrap" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &src) {
    std::cout << "DiamondTrap" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    this->_name = src._name;
    this->_hitPoint = src._hitPoint;
    this->_energyPoint = src._energyPoint;
    this->_attackDamage = src._attackDamage;
    this->_gateKeeperMode = src._gateKeeperMode;
    if (this->_highFiveCounter) delete this->_highFiveCounter;
    this->_highFiveCounter = new unsigned int;
    *(this->_highFiveCounter) = *src._highFiveCounter;
    return *this;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    std::cout << "DiamondTrap" << " " << name << MSG_CONSTRUCTOR << std::endl;
    this->_name = name;
    this->_hitPoint = FragTrap::_initialHitPoint_;
    this->_energyPoint = ScavTrap::_initialEnergyPoint_;
    this->_attackDamage = FragTrap::_initialAttackDamage_;
}

void DiamondTrap::whoAmI(void) const {
    std::cout << "Inheritant _name : " << ClapTrap::_name << std::endl;
    std::cout << "My class _name : " << this->_name << std::endl;
}
