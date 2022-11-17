/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 15:32:00 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

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
