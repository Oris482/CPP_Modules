/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:59:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 15:07:35 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &src);
        Fixed& operator= (const Fixed &src);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
