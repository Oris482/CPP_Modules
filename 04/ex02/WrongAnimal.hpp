/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:05:14 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:16:36 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_H__
# define WRONGANIMAL_H__

# include <string>

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class WrongAnimal {
    protected:
        explicit WrongAnimal(const std::string type);
        std::string _type;

    public:
        WrongAnimal(void);
        ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal& operator= (const WrongAnimal &src);

        std::string getType(void) const;
        void makeSound(void) const;
};

#endif
