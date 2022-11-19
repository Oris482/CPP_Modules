/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:56 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:30:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::bsp( Point const a, Point const b, Point const c, Point const point) {
    const Fixed abcTriangleArea = Point::getTriangleArea(a, b, c);
    if (abcTriangleArea == 0) return false;
    const Fixed abpTriangleArea = Point::getTriangleArea(a, b, point);
    const Fixed acpTriangleArea = Point::getTriangleArea(a, c, point);
    const Fixed bcpTriangleArea = Point::getTriangleArea(b, c, point);

    std::cout << "abc Area : " << abcTriangleArea << std::endl;
    std::cout << "abp Area : " << abpTriangleArea << std::endl;
    std::cout << "acp Area : " << acpTriangleArea << std::endl;
    std::cout << "bcp Area : " << bcpTriangleArea << std::endl;
    if (abpTriangleArea == 0 || acpTriangleArea == 0 || bcpTriangleArea == 0)
        return false;
    const Fixed threeSmallTriangleArea = abpTriangleArea + acpTriangleArea + bcpTriangleArea;
    std::cout << "abp + acp + bcp : " << threeSmallTriangleArea << std::endl;
    std::cout << "abc - (abp + acp + bcp) : " << (abcTriangleArea - threeSmallTriangleArea) << std::endl;
    if ((abcTriangleArea - threeSmallTriangleArea).toAbs() > Fixed::getEpsilon())
        return false;
    return true;
}
