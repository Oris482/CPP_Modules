/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 22:41:12 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H__
# define POINT_H__

#include "Fixed.hpp"

class Point {
    private:
        Fixed _x;
        Fixed _y;
        
    public:
        Point(void);
        ~Point(void);
        Point(const Point &src);
        Point& operator= (const Point &src);

        Point(const float x, const float y);
        void printPos(std::string name) const;

        static Fixed getVectorCrossProduct(const Point &base, const Point &A, const Point &B);
};

#endif
