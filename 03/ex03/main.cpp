/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:53:50 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 20:49:45 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "DiamondTrap.hpp"

int main(void) {
    {
        std::cout << "-------------------------------------" << std::endl;
        DiamondTrap ftseoul("ftseoul");
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.attack("saffy");
        ftseoul.guardGate();
        ftseoul.highFivesGuys();
        ftseoul.highFivesGuys();
        ftseoul.whoAmI();
    }
    std::cout << "#####################################" << std::endl;
    {
        std::cout << "-------------------------------------" << std::endl;
        DiamondTrap *allocatedFtseoul = new DiamondTrap("allocatedFtseoul");
        std::cout << "-------------------------------------" << std::endl;
        allocatedFtseoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        allocatedFtseoul->attack("saffy");
        allocatedFtseoul->guardGate();
        allocatedFtseoul->highFivesGuys();
        allocatedFtseoul->highFivesGuys();
        allocatedFtseoul->whoAmI();
        std::cout << "-------------------------------------" << std::endl;
        DiamondTrap *copyFtsoul = new DiamondTrap(*allocatedFtseoul);
        std::cout << "-------------------------------------" << std::endl;
        copyFtsoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        copyFtsoul->guardGate();
        copyFtsoul->highFivesGuys();
        copyFtsoul->whoAmI();
        delete allocatedFtseoul;
        delete copyFtsoul;
    }
    std::cout << "#####################################" << std::endl;
    {
        std::cout << "-------------------------------------" << std::endl;
        ClapTrap *upCastedFtseoul = new DiamondTrap("upCastedFtseoul");
        std::cout << "-------------------------------------" << std::endl;
        upCastedFtseoul->printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        upCastedFtseoul->attack("saffy");
        // upCastedFtseoul->whoAmI();
        delete upCastedFtseoul;
    }
    system("leaks UnitTrap4");
    return 0;
}
