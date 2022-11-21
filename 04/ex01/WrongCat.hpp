/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:07:31 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:08:03 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_H__
# define WRONGCAT_H__

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat(void);
        ~WrongCat(void);
        WrongCat(const WrongCat &src);
        WrongCat& operator= (const WrongCat &src);

        void makeSound(void) const;
};

#endif
