/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:08:41 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:51:26 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // Animal class should not be instantiable
    // {
    //     Animal justAnimal;
    //     Animal *animalPointList[3];

    //     animalPointList[0] = new Dog();
    //     animalPointList[1] = new Cat();
    //     animalPointList[2] = new Animal();

    //     delete animalPointList[0];
    //     delete animalPointList[1];
    // }
    std::cout << "####################################" << std::endl;
    // additional test case
    {
        Animal *animalList[10];

        std::cout << "-----------------------------------" << std::endl;
        for (int i = 0; i < 5; ++i) {
            animalList[i] = new Dog();
        }
        std::cout << "-----------------------------------" << std::endl;
        for (int i = 5; i < 10; ++i) {
            animalList[i] = new Cat();
        }
        std::cout << "-----------------------------------" << std::endl;
        for (int i = 0; i < 10; ++i) {
            delete animalList[i];
        }
        std::cout << "-----------------------------------" << std::endl;
    }
    std::cout << "####################################" << std::endl;
    // deep copy check
    {
        Dog *choko = new Dog();
        choko->getBrain().addSingleIdea("Dog is the best animal");
        choko->getBrain().addSingleIdea("Cat is the worst animal");
        std::cout << "-----------choko's brain----------" << std::endl;
        choko->getBrain().printAllIdeas();
        std::cout << "-----------------------------------" << std::endl;
        Dog *happy = new Dog(*choko);
        std::cout << "-----------happy's brain----------" << std::endl;
        happy->getBrain().printAllIdeas();
        std::cout << "-----------------------------------" << std::endl;
        happy->getBrain().addSingleIdea("I love choko");
        std::cout << "-----------happy's brain----------" << std::endl;
        happy->getBrain().printAllIdeas();
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "-----------choko's brain----------" << std::endl;
        choko->getBrain().printAllIdeas();
        std::cout << "-----------------------------------" << std::endl;
        delete choko;
        std::cout << "-----------happy's brain----------" << std::endl;
        happy->getBrain().printAllIdeas();
        std::cout << "-----------------------------------" << std::endl;
        delete happy;
        std::cout << "-----------------------------------" << std::endl;
    }
    system("leaks NoJustAnimal");
    return 0;
}
