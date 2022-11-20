/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:53:50 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/20 22:41:50 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void) {
    {
        std::cout << "-------------------------------------" << std::endl;
        ClapTrap ftseoul("ftseoul");
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        ftseoul.attack("saffy");
    }
    std::cout << "#####################################" << std::endl;
    {
        std::cout << "-------------------------------------" << std::endl;
        ScavTrap saffy("saffy");
        std::cout << "-------------------------------------" << std::endl;
        saffy.printMyStatus();
        std::cout << "-------------------------------------" << std::endl;
        saffy.attack("ftseoul");
        saffy.guardGate();
    }
    return 0;
}
