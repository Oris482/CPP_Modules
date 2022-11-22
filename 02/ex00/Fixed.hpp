/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 17:49:36 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H__
# define FIXED_H__

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &src);
        Fixed& operator= (const Fixed &src);
        const int& getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
