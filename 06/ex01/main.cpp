/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:05:02 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/28 20:19:47 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
    Serializer Box;
    Data firstData;
    uintptr_t serializedValue;
    Data* deserializedPTR = NULL;

    firstData.c = 'f';
    firstData.i = 42;
    
    std::cout << "Original data address: " << &firstData << std::endl;
    serializedValue = Box.serialize(&firstData);
    std::cout << "Serialized value: " << serializedValue << std::endl;
    deserializedPTR = Box.deserialize(serializedValue);
    std::cout << "Deserialized value: " << deserializedPTR << std::endl;
    std::cout << "Get char: " << deserializedPTR->c << std::endl;
    std::cout << "Get int: " << deserializedPTR->i << std::endl;

    return 0;
}
