/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:48:24 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:22:17 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H__
# define DOG_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain *_brain;

    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog &src);
        Dog& operator= (const Dog &src);

        void makeSound(void) const;
        Brain& getBrain(void) const;
};

#endif
