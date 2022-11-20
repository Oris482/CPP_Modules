/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:31 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/20 21:32:14 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_H__
# define CLAPTRAP_H__

# include <string>

class ClapTrap {
    private:
        ClapTrap(void);
        static const std::string unitType;
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;

    public:
        ~ClapTrap(void);
        ClapTrap(const ClapTrap &src);
        ClapTrap& operator= (const ClapTrap &src);

        ClapTrap(std::string name);

        void printMyStatus(void) const;
        bool checkCanAction(void) const;
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
