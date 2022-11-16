/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:17:34 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 20:38:29 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(void) {
    Zombie stackZombieA("mainstackZombie");
    Zombie* heapZombieA = newZombie("newHeapZombie");

    stackZombieA.announce();
    heapZombieA->announce();
    delete(heapZombieA);
    randomChump("randomStackZombie");
    return 0;
}
