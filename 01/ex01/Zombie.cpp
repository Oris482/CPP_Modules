/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:06:32 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:47:31 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define MSG_ZOMBIE_SOUND ": BraiiiiiiinnnzzzZ..."

Zombie::Zombie(void) {
    this->isDefined = false;
    std::cout << "Undefined zombie constructed" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->_name = name;
    this->isDefined = true;
    std::cout << this->_name << " constructed" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->_name << " destructed" << std::endl;
}

void Zombie::announce(void) const {
    if (this->isDefined)
        std::cout << this->_name << ": " << MSG_ZOMBIE_SOUND << std::endl;
    else
        std::cout << "Error! Undefined Zombie!" << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
    this->isDefined = true;
}
