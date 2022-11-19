/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:15:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:49:42 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    // Subject code
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    // Selft test code
    std::cout << "Self test code" << std::endl;
    {
        // Weapon gun = Weapon();
        Weapon gun = Weapon("K2");
        // HumanA jaesjeon("jaesjeon");
        HumanA jaesjeon("jaesjeon", gun);
        jaesjeon.attack();
        gun.setType("M16");
        jaesjeon.attack();
    }
    {
        Weapon gun = Weapon("K2");
        HumanB jaesjeon("jaesjeon");
        jaesjeon.attack();
        jaesjeon.setWeapon(gun);
        jaesjeon.attack();
    }
    return 0;
}
