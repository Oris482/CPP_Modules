/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:17:34 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 21:36:51 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(void) {
    Zombie* zombieArmy;
    int armySize = 9;
    std::string armyName = "Kombie";

    std::cout << "> Start allocating zombieArmy >" << std::endl;
    zombieArmy = zombieHorde(armySize, armyName);
    std::cout << "< Finish allocating zombieArmy <" << std::endl;
    std::cout << "> Start announce zombieArmy >" << std::endl;
    for (int i = 0; i < armySize; ++i) {
        zombieArmy[i].announce();
    }
    std::cout << "< Finish announce zombieArmy <" << std::endl;
    std::cout << "> Start deleting zombieArmy >" << std::endl;
    delete[] zombieArmy;
    std::cout << "< Finish deleting zombieArmy <" << std::endl;
    return 0;
}
