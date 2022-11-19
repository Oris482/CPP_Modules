/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:36 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 23:04:15 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Triangle.hpp"

int main( void ) {
    std::cout << "Integer case" << std::endl;
    Point A(0, 0);
    Point B(10, 10);
    Point C(20, 0);
    Triangle triangle(A, B, C);
    Point P(5, 5);

    std::cout << "-------------------------------------------" << std::endl;
    triangle.printInfo("First");
    P.printPos("Point");
    std::cout << std::endl;
    triangle.checkPointInside(P);
    std::cout << "-------------------------------------------" << std::endl;
    P = Point(10, 5);
    std::cout << "-------------------------------------------" << std::endl;
    triangle.printInfo("Second");
    P.printPos("Point");
    std::cout << std::endl;
    triangle.checkPointInside(P);
    std::cout << "-------------------------------------------" << std::endl;
    
    std::cout << "Float case" << std::endl;
    A = Point(0.3f, 0.2f);
    B = Point(10.9f, 10.7f);
    C = Point(20.2f, 0.3f);
    triangle = Triangle(A, B, C);
    P = Point(-5.6f, 5.1f);

    std::cout << "-------------------------------------------" << std::endl;
    triangle.printInfo("Third");
    P.printPos("Point");
    std::cout << std::endl;
    triangle.checkPointInside(P);
    std::cout << "-------------------------------------------" << std::endl;
    P = Point(5.6f, 5.1f);
    std::cout << "-------------------------------------------" << std::endl;
    triangle.printInfo("Fourth");
    P.printPos("Point");
    std::cout << std::endl;
    triangle.checkPointInside(P);
    std::cout << "-------------------------------------------" << std::endl;
    return 0;
}
