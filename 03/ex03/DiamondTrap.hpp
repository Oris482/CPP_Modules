/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:02:26 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 20:38:09 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_H__
# define DIAMONDTRAP_H__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
    private:
        DiamondTrap(void);
        std::string _name;

    public:
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap &src);
        DiamondTrap& operator= (const DiamondTrap &src);

        explicit DiamondTrap(const std::string name);

        using ScavTrap::attack;

        void whoAmI(void) const;
};

#endif
