/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:06:32 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 20:36:50 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

#define MSG_ZOMBIE_SOUND ": BraiiiiiiinnnzzzZ..."

Zombie::Zombie(std::string name) {
    this->_name = name;
    std::cout << this->_name << " constructed" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->_name << " destructed" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->_name << ": " << MSG_ZOMBIE_SOUND << std::endl;
}
