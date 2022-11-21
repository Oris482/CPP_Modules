/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:48:24 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 22:58:14 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H__
# define DOG_H__

# include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog &src);
        Dog& operator= (const Dog &src);

        void makeSound(void) const;
};

#endif
