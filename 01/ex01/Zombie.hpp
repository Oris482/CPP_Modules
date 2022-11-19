/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:03:19 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:47:23 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>

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

#endif
