/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:14 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:49:16 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H__
# define HUMANA_H__

# include "Weapon.hpp"

class HumanA {
    private:
        Weapon& _weapon;
        std::string _name;
    
    public:
        explicit HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void attack(void) const;
};

#endif
