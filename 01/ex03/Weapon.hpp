/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:48:49 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H__
# define WEAPON_H__

# include <string>

class Weapon {
    private:
        Weapon(void);
        std::string _type;

    public:
        explicit Weapon(const std::string &type);
        ~Weapon(void);
        const std::string &getType(void) const;
        void setType(const std::string &type);
};

#endif
