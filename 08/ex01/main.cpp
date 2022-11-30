/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:12 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 17:42:56 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
    // subject test case
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // custom test case
    std::cout << std::endl << "----------------------------------" <<std::endl;
    std::vector<int> originIntVec;
    for (int i = 0; i < 10; i++) {
        originIntVec.push_back(i);
    }
    Span iterSpan(10);
    iterSpan.addNumber(originIntVec.begin(), originIntVec.end());
    std::cout << iterSpan.shortestSpan() << std::endl;
    std::cout << iterSpan.longestSpan() << std::endl;
    std::cout << std::endl << "----------------------------------" <<std::endl;
    Span emptySpan(0);
    try {
        emptySpan.addNumber(1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        emptySpan.shortestSpan();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        emptySpan.longestSpan();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
