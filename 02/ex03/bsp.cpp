/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:56 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 22:41:04 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Triangle.hpp"

bool Triangle::bsp( Point const a, Point const b, Point const c, Point const point) {
    const Triangle abcTriangle(a, b, c);
    const Triangle abpTriangle(a, b, point);
    const Triangle acpTriangle(a, c, point);
    const Triangle bcpTriangle(b, c, point);

    std::cout << "abc Area : " << abcTriangle._area << std::endl;
    std::cout << "abp Area : " << abpTriangle._area << std::endl;
    std::cout << "acp Area : " << acpTriangle._area << std::endl;
    std::cout << "bcp Area : " << bcpTriangle._area << std::endl;
    if (abpTriangle._area == 0 || acpTriangle._area == 0 || bcpTriangle._area == 0)
        return false;
    const Fixed threeSmallTriangleArea = abpTriangle._area + acpTriangle._area + bcpTriangle._area;
    std::cout << "abp + acp + bcp : " << threeSmallTriangleArea << std::endl;
    std::cout << "abc - (abp + acp + bcp) : " << (abcTriangle._area - threeSmallTriangleArea) << std::endl;
    if ((abcTriangle._area - threeSmallTriangleArea).toAbs() > Fixed::getEpsilon())
        return false;
    return true;
}
