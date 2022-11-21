/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:36:43 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:48:14 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_H__
# define ANIMAL_H__

# include <string>

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class Animal {
    protected:
        explicit Animal(const std::string type);
        std::string _type;

    public:
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal &src);
        Animal& operator= (const Animal &src);

        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif
