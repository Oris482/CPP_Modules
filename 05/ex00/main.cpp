/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 15:50:15 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
    {
        Bureaucrat staticPerson("staticPerson", 3);
        std::cout << staticPerson << std::endl;
        try {
            staticPerson.promote();
        } catch (std::exception &e) {
            std::cout <<  e.what() << std::endl;
        }
        std::cout << staticPerson << std::endl;
        try {
            staticPerson.promote();
        } catch (std::exception &e) {
            std::cout <<  e.what() << std::endl;
        }
        std::cout << staticPerson << std::endl;
        try {
            staticPerson.promote();
        } catch (std::exception &e) {
            std::cout <<  e.what() << std::endl;
        }
        std::cout << staticPerson << std::endl;
    }
    std::cout << "######################################################" << std::endl;
    {
        Bureaucrat *heapPerson = new Bureaucrat("heapPerson", 148);
        std::cout << *heapPerson << std::endl;
        try {heapPerson->demote();}
        catch (std::exception &e) {std::cout <<  e.what() << std::endl;}
        std::cout << *heapPerson << std::endl;
        try {heapPerson->demote();}
        catch (std::exception &e) {std::cout <<  e.what() << std::endl;}
        std::cout << *heapPerson << std::endl;
        try {heapPerson->demote();}
        catch (std::exception &e) {std::cout <<  e.what() << std::endl;}
        std::cout << *heapPerson << std::endl;
        delete heapPerson;
    }
    std::cout << "######################################################" << std::endl;
    {     
        Bureaucrat *tempPerson = new Bureaucrat("willBeCopied", 3);
        tempPerson->promote();
        Bureaucrat *copyPerson = new Bureaucrat(*tempPerson);
        delete tempPerson;
        
        std::cout << *copyPerson << std::endl;
        try {copyPerson->promote();}
        catch (std::exception &e) {std::cout <<  e.what() << std::endl;}
        std::cout << *copyPerson << std::endl;
        try {copyPerson->promote();}
        catch (std::exception &e) {std::cout <<  e.what() << std::endl;}
        std::cout << *copyPerson << std::endl;
        delete copyPerson;
    }
    return 0;
}
