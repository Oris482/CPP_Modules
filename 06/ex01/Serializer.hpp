/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:08:54 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/28 20:14:40 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_H__
# define SERIALIZER_H__

# include <cstdint>
# include "Data.hpp"

class Serializer {
    private:
        Serializer(const Serializer &src);
        Serializer& operator= (const Serializer &src);
        
    public:
        Serializer(void);
        ~Serializer(void);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif
