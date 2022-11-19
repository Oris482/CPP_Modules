/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 21:04:52 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H__
# define FIXED_H__

# include <ostream>

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &src);
        Fixed& operator= (const Fixed &src);
        Fixed(const int num);
        Fixed(const float num);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<< (std::ostream& os, const Fixed& target);

#endif
