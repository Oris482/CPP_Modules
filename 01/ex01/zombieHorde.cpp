/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:41:08 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 21:36:36 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombieList = new Zombie[N];

    std::cout << ">> Start initializing zombies >>" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::string eachName = name;
        zombieList[i].setName(eachName.append(std::to_string(i)));
    }
    std::cout << "<< Finish initializing zombies <<" << std::endl;
    return zombieList;
}
