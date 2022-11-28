/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:19:02 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 03:27:18 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void) {
    {
        std::cout << "############## SWAP TEST ###############" << std::endl;
        int intArray[2] = {2, 4};
        std::cout << intArray[0] << ", " << intArray[1] << std::endl;
        swap(&intArray[0], &intArray[1]);
        std::cout << intArray[0] << ", " << intArray[1] << std::endl;

        char charArray[5] = {'a', 'd', 'c', 'b', 'e'};
        for (int i = 0; i < 5; ++i) {std::cout << charArray[i];}
        std::cout << std::endl;
        swap(&charArray[1], &charArray[3]);
        for (int i = 0; i < 5; ++i) {std::cout << charArray[i];}
        std::cout << std::endl;
    }
    {
        std::cout << "############## MIN TEST ###############" << std::endl;
        int intArray[2] = {2, 4};
        std::cout << min(intArray[0], intArray[1]) << std::endl;

        char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
        std::cout << min(charArray[0], charArray[1]) << std::endl;
        std::cout << min(charArray[3], charArray[0]) << std::endl;
        std::cout << min(charArray[0], charArray[3]) << std::endl;
        std::cout << min(charArray[2], charArray[4]) << std::endl;
        std::cout << min(charArray[4], charArray[2]) << std::endl;
    }
    {
        std::cout << "############## MAX TEST ###############" << std::endl;
        int intArray[2] = {2, 4};
        std::cout << max(intArray[0], intArray[1]) << std::endl;

        char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
        std::cout << max(charArray[0], charArray[1]) << std::endl;
        std::cout << max(charArray[3], charArray[0]) << std::endl;
        std::cout << max(charArray[0], charArray[3]) << std::endl;
        std::cout << max(charArray[2], charArray[4]) << std::endl;
        std::cout << max(charArray[4], charArray[2]) << std::endl;
    }
    
    return 0;
}
