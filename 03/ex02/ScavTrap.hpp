/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:17:26 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 18:37:31 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_H__
# define SCAVTRAP_H__

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    private:
        ScavTrap(void);
        bool _gateKeeperMode;

    public:
        ~ScavTrap(void);
        ScavTrap(const ScavTrap &src);
        ScavTrap& operator= (const ScavTrap &src);

        ScavTrap(std::string name);

        void attack(const std::string &target);

        void guardGate(void);
};

#endif
