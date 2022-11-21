/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:53:48 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 20:38:00 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_H__
# define FRAGTRAP_H__

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    protected:
        FragTrap(void);
        unsigned int *_highFiveCounter;

    public:
        ~FragTrap(void);
        FragTrap(const FragTrap &src);
        FragTrap& operator= (const FragTrap &src);

        explicit FragTrap(const std::string name);

        void attack(const std::string &target);

        void highFivesGuys(void);
        unsigned int getHighFiveCount(void) const;
};

#endif
