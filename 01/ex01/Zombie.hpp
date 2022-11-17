/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:03:19 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 21:27:58 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;
        void setName(std::string name);

    private:
        bool isDefined;
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
