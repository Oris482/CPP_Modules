/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:36 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:39:30 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
    std::cout << "Integer case" << std::endl;
    Point A(0, 0);
    Point B(10, 10);
    Point C(20, 0);
    Point P(5, 5);

    P.checkInsideOfTriangle(A, B, C);
    P = Point(10, 5);
    P.checkInsideOfTriangle(A, B, C);
    
    std::cout << "Float case" << std::endl;
    A = Point(0.3f, 0.2f);
    B = Point(10.9f, 10.7f);
    C = Point(20.2f, 0.3f);
    P = Point(-5.6f, 5.1f);

    P.checkInsideOfTriangle(A, B, C);
    P = Point(5.6f, 5.1f);
    P.checkInsideOfTriangle(A, B, C);
    return 0;
}
