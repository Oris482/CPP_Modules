/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:00:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:01:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_H__
# define CAT_H__

# include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat &src);
        Cat& operator= (const Cat &src);

        void makeSound(void) const;
};

#endif
