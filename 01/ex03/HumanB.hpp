/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:13 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:49:34 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_H__
# define HUMANB_H__

#include "Weapon.hpp"

class HumanB {
    private:
        HumanB(void);
        Weapon *_weapon;
        std::string _name;
    
    public:
        explicit HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon &weapon);
        void attack(void) const;
};

#endif
