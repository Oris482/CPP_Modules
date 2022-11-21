/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:53:50 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 18:41:24 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    {
        std::cout << "-------------------------------------" << std::endl;
        FragTrap ftseoul("ftseoul");
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.attack("saffy");
        ftseoul.highFivesGuys();
        ftseoul.highFivesGuys();
        ftseoul.highFivesGuys();
    }
    std::cout << "#####################################" << std::endl;
    {
        std::cout << "-------------------------------------" << std::endl;
        FragTrap *allocatedFtseoul = new FragTrap("allocatedFtseoul");
        std::cout << "-------------------------------------" << std::endl;
        allocatedFtseoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        allocatedFtseoul->attack("saffy");
        allocatedFtseoul->highFivesGuys();
        allocatedFtseoul->highFivesGuys();
        allocatedFtseoul->highFivesGuys();
        std::cout << "-------------------------------------" << std::endl;
        FragTrap *copyFtsoul = new FragTrap(*allocatedFtseoul);
        std::cout << "-------------------------------------" << std::endl;
        copyFtsoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        copyFtsoul->highFivesGuys();
        delete allocatedFtseoul;
        delete copyFtsoul;
    }
    std::cout << "#####################################" << std::endl;
    {
        std::cout << "-------------------------------------" << std::endl;
        ClapTrap *upCastedFtseoul = new FragTrap("upCastedFtseoul");
        std::cout << "-------------------------------------" << std::endl;
        upCastedFtseoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        upCastedFtseoul->attack("saffy");
        // upCastedFtseoul->highFivesGuys();
        delete upCastedFtseoul;
    }
    system("leaks UnitTrap3");
    return 0;
}
