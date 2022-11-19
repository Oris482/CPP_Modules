/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:36 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 18:07:53 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    // subject test case
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // custom test case
    Fixed baseNum(5.05f);
    Fixed sameNum(5.05f);
    Fixed smallNum(5.04f);
    Fixed bigNum(5.06f);
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Custom Test case" << std::endl;
    std::cout << "baseNum : " << baseNum << std::endl;
    std::cout << "sameNum : " << sameNum << std::endl;
    std::cout << "smallNum : " << smallNum << std::endl;
    std::cout << "bigNum : " << bigNum << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Comparison operator" << std::endl;
    std::cout << "baseNum == sameNum : " << (baseNum == sameNum) << std::endl; 
    std::cout << "baseNum != sameNum : " << (baseNum != sameNum) << std::endl; 
    std::cout << "baseNum > sameNum : " << (baseNum > sameNum) << std::endl; 
    std::cout << "baseNum >= sameNum : " << (baseNum >= sameNum) << std::endl; 
    std::cout << "baseNum < sameNum : " << (baseNum < sameNum) << std::endl; 
    std::cout << "baseNum <= sameNum : " << (baseNum <= sameNum) << std::endl; 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "baseNum == smallNum : " << (baseNum == smallNum) << std::endl; 
    std::cout << "baseNum != smallNum : " << (baseNum != smallNum) << std::endl; 
    std::cout << "baseNum > smallNum : " << (baseNum > smallNum) << std::endl; 
    std::cout << "baseNum >= smallNum : " << (baseNum >= smallNum) << std::endl; 
    std::cout << "baseNum < smallNum : " << (baseNum < smallNum) << std::endl; 
    std::cout << "baseNum <= smallNum : " << (baseNum <= smallNum) << std::endl; 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "baseNum == bigNum : " << (baseNum == bigNum) << std::endl; 
    std::cout << "baseNum != bigNum : " << (baseNum != bigNum) << std::endl; 
    std::cout << "baseNum > bigNum : " << (baseNum > bigNum) << std::endl; 
    std::cout << "baseNum >= bigNum : " << (baseNum >= bigNum) << std::endl; 
    std::cout << "baseNum < bigNum : " << (baseNum < bigNum) << std::endl; 
    std::cout << "baseNum <= bigNum : " << (baseNum <= bigNum) << std::endl; 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Arithmetic operator" << std::endl;
    std::cout << "baseNum + bigNum : " << (baseNum + bigNum) << std::endl; 
    std::cout << "baseNum - bigNum : " << (baseNum - bigNum) << std::endl; 
    std::cout << "baseNum * bigNum : " << (baseNum * bigNum) << std::endl; 
    std::cout << "baseNum / bigNum : " << (baseNum / bigNum) << std::endl; 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Increment operator" << std::endl;
    std::cout << "baseNum : " << baseNum << std::endl; 
    std::cout << "baseNum++ : " << baseNum++ << std::endl; 
    std::cout << "baseNum : " << baseNum << std::endl; 
    std::cout << "++baseNum : " << ++baseNum << std::endl; 
    std::cout << "baseNum : " << baseNum << std::endl; 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Decrement operator" << std::endl;
    std::cout << "baseNum : " << baseNum << std::endl; 
    std::cout << "baseNum-- : " << baseNum-- << std::endl; 
    std::cout << "baseNum : " << baseNum << std::endl; 
    std::cout << "--baseNum : " << --baseNum << std::endl; 
    std::cout << "baseNum : " << baseNum << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Comparision member function" << std::endl;
    baseNum = 3;
    smallNum = 1;
    bigNum = 5;
    std::cout << "baseNum : " << baseNum << std::endl;
    std::cout << "smallNum : " << smallNum << std::endl;
    std::cout << "bigNum : " << bigNum << std::endl;
    std::cout << "min(baseNum, smallNum) : " << Fixed::min(baseNum, smallNum) << std::endl;
    std::cout << "min(baseNum, bigNum) : " << Fixed::min(baseNum, bigNum) << std::endl;
    std::cout << "max(baseNum, smallNum) : " << Fixed::max(baseNum, smallNum) << std::endl;
    std::cout << "max(baseNum, bigNum) : " << Fixed::max(baseNum, bigNum) << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    const Fixed constBaseNum(4);
    const Fixed constSmallNum(2);
    const Fixed constBigNum(6);
    std::cout << "constBaseNum : " << constBaseNum << std::endl;
    std::cout << "constSmallNum : " << constSmallNum << std::endl;
    std::cout << "constBigNum : " << constBigNum << std::endl;
    std::cout << "min(constBaseNum, constSmallNum) : " << Fixed::min(constBaseNum, constSmallNum) << std::endl;
    std::cout << "min(constBaseNum, constBigNum) : " << Fixed::min(constBaseNum, constBigNum) << std::endl;
    std::cout << "max(constBaseNum, constSmallNum) : " << Fixed::max(constBaseNum, constSmallNum) << std::endl;
    std::cout << "max(constBaseNum, constBigNum) : " << Fixed::max(constBaseNum, constBigNum) << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "min(3.3f, 3.7f) : " << Fixed::min(3.3f, 3.7f) << std::endl;
    std::cout << "max(3.3f, 3.7f) : " << Fixed::max(3.3f, 3.7f) << std::endl;
    return 0;
}
