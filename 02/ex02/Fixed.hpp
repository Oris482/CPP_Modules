/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 22:16:56 by jaesjeon         ###   ########.fr       */
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

        bool operator> (const Fixed &target) const;
        bool operator>= (const Fixed &target) const;
        bool operator< (const Fixed &target) const;
        bool operator<= (const Fixed &target) const;
        bool operator== (const Fixed &target) const;
        bool operator!= (const Fixed &target) const;
        Fixed operator+ (const Fixed &target) const;
        Fixed operator- (const Fixed &target) const;
        Fixed operator* (const Fixed &target) const;
        Fixed operator/ (const Fixed &target) const;
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        
        static float getEpsilon(void);
        static Fixed& min(Fixed &A, Fixed &B);
        static const Fixed& min(const Fixed &A, const Fixed &B);
        static Fixed& max(Fixed &A, Fixed &B);
        static const Fixed& max(const Fixed &A, const Fixed &B);
};

std::ostream& operator<< (std::ostream& os, const Fixed& target);

#endif
