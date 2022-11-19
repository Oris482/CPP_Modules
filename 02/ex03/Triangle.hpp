/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:15:15 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 22:41:07 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TRIANGLE_H__
# define TRIANGLE_H__

# include "Point.hpp"

class Triangle {
    private:
        Point _a;
        Point _b;
        Point _c;
        bool _isTriangle;
        Fixed _area;

    public:
        Triangle(void);
        ~Triangle(void);
        Triangle(const Triangle &src);
        Triangle& operator= (const Triangle &src);

        Triangle(const Point a, const Point b, const Point c);

        void printInfo(std::string name) const;
        Fixed getTriangleArea(void) const;
        void checkPointInside(Point &P) const;

        static bool isCanBeTriangle(const Point &A, const Point &B, const Point &C);
        static bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif
