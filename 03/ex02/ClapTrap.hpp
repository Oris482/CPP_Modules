/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:20:31 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:46 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_H__
# define CLAPTRAP_H__

# include <string>

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR "Destructor called"
# define MSG_OPERATOR " operator called"

class ClapTrap {
    protected:
        ClapTrap(void);
        ClapTrap(std::string name, unsigned int hitPoint, \
                    unsigned int energyPoint, unsigned int attackDamage);
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;

    public:
        virtual ~ClapTrap(void);
        ClapTrap(const ClapTrap &src);
        ClapTrap& operator= (const ClapTrap &src);

        ClapTrap(const std::string name);

        void printMyStatus(void) const;
        bool checkCanAction(void) const;
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
