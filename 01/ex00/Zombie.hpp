/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:03:19 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 20:35:14 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;

    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
