/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:47:00 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/12/04 19:20:11 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void) {
    int intArray[5] = {1, 3, 5, 7, 9};
    iter(intArray, 5, printAll);
    std::cout << std::endl;
    iter(intArray, 5, plusOne);
    iter(intArray, 5, printAll);
    std::cout << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(charArray, 5, printAll);
    std::cout << std::endl;
    iter(charArray, 5, plusOne);
    iter(charArray, 5, printAll);
    std::cout << std::endl;

    return 0;
}
