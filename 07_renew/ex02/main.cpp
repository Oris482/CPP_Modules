/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:06:31 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 19:05:48 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int argc, char *argv[])
{
    // subject tester
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // custom test
    std::cout << "##################################" << std::endl;
    if (argc > 1)
    {
        Array<std::string> multiStr(argc - 1);
        for (int i = 0; i < argc - 1; ++i) {
            multiStr[i] = std::string(argv[i + 1]);
        }
        std::cout << "Print array" << std::endl;
        for (int i = 0; i < argc - 1; ++i) {
            std::cout << i << ": " << multiStr[i] << std::endl;
        }
        
        std::cout << std::endl;
        const Array<std::string> constArray = multiStr;
        for (int i = 0; i < argc - 1; ++i) {
            std::cout << i << ": " << constArray[i] << std::endl;
        }        
    }
    return 0;
}
