/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:47:00 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 22:02:48 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void plusOne(T& target) {
    target += 1;
}

int main(void) {
    int intArray[5] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i];
    }
    std::cout << std::endl;
    iter(intArray, 5, plusOne);
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i];
    }
    std::cout << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    for (int i = 0; i < 5; ++i) {
        std::cout << charArray[i];
    }
    std::cout << std::endl;
    iter(charArray, 5, plusOne);
    for (int i = 0; i < 5; ++i) {
        std::cout << charArray[i];
    }
    std::cout << std::endl;

    return 0;
}
