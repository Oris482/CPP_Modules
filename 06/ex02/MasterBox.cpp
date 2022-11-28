/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MasterBox.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:31:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 03:00:53 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MasterBox.hpp"

bool MasterBox::isSeedCreated = false;

MasterBox::MasterBox(void) {
    createSeed();
}

MasterBox::~MasterBox(void) {}

void MasterBox::createSeed(void) {
    if (isSeedCreated) return ;

    srand(time(NULL));
}

Base* MasterBox::generate(void) const {
    switch (rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void MasterBox::identify(Base* p) const {
    const std::string classList[3] = {"A", "B", "C"};
    int i = -1;

    std::cout << "Pointer parameter check: ";
    if (dynamic_cast<A*>(p) != NULL) i = 0;
    else if (dynamic_cast<B*>(p) != NULL) i = 1;
    else if (dynamic_cast<C*>(p) != NULL) i = 2;

    if (i == -1) std::cout << "There is no match class" << std::endl;
    else std::cout << "This class is " + classList[i] + " class" << std::endl;
}

void MasterBox::identify(Base& p) const {
    const std::string classList[3] = {"A", "B", "C"};
    int i = -1;
    
    std::cout << "Reference parameter check: ";
    try {
        (void)dynamic_cast<A&>(p);
        i = 0;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(p);
        i = 1;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(p);
        i = 2;
    } catch (std::exception &e) {}

    if (i == -1) std::cout << "There is no match class" << std::endl;
    else std::cout << "This class is " + classList[i] + " class" << std::endl;
}
