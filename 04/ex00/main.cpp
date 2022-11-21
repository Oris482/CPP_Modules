/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:08:41 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:15:01 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // subject test case
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    // custom test case
    std::cout << "---------------------------------" << std::endl;
    {
        const WrongAnimal *wrongUndefined = new WrongAnimal();
        const WrongAnimal *upCastedWrongCat = new WrongCat();
        std::cout << wrongUndefined->getType() << std::endl;
        std::cout << upCastedWrongCat->getType() << std::endl;
        wrongUndefined->makeSound();
        upCastedWrongCat->makeSound();
        delete wrongUndefined;
        delete upCastedWrongCat;
    }
    return 0;
}
