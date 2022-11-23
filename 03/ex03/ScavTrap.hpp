/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:17:26 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/23 12:13:48 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_H__
# define SCAVTRAP_H__

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    protected:
        ScavTrap(void);
        bool _gateKeeperMode;
        static const unsigned int _initialHitPoint_ = 100;
        static const unsigned int _initialEnergyPoint_ = 50;
        static const unsigned int _initialAttackDamage_ = 20;

    public:
        ~ScavTrap(void);
        ScavTrap(const ScavTrap &src);
        ScavTrap& operator= (const ScavTrap &src);

        explicit ScavTrap(const std::string name);

        void attack(const std::string &target);

        void guardGate(void);
};

#endif
