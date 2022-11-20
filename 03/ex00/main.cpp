/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:53:50 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/20 21:33:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
    {
        std::cout << "HP 0 case" << std::endl;
        
        ClapTrap userA("42seoul");
        userA.attack("SSAFY");
        userA.takeDamage(5);
        userA.beRepaired(2);
        userA.attack("UTEKO");
        userA.takeDamage(5);
        userA.attack("SSAFY");
        userA.beRepaired(2);
        userA.takeDamage(5);
        userA.attack("SSAFY");
        userA.beRepaired(2);
        userA.takeDamage(5);
        userA.printMyStatus();

        std::cout << std::endl;
        std::cout << "copy case 1" << std::endl;
        ClapTrap userC("undefine");
        userC = userA;
    }
    {
        std::cout << std::endl;
        std::cout << "EP 0 case" << std::endl;
        ClapTrap userB("jaesjeon");
        userB.attack("42seoul_1");
        userB.attack("42seoul_2");
        userB.attack("42seoul_3");
        userB.attack("42seoul_4");
        userB.attack("42seoul_5");
        userB.attack("42seoul_6");
        userB.attack("42seoul_7");
        userB.attack("42seoul_8");
        userB.attack("42seoul_9");
        userB.attack("42seoul_10");
        userB.attack("42seoul_11");
        userB.beRepaired(2);
        userB.takeDamage(5);
        userB.takeDamage(7);
        userB.printMyStatus();

        std::cout << std::endl;
        std::cout << "copy case 2" << std::endl;
        ClapTrap userD(userB);
    }
    return 0;
}
