/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:04 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 21:01:03 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook myPhoneBook;
    std::string userInput;
    std::string contactData[5];

    while (true) {
        std::cout << "COMMAND : ";
        std::getline(std::cin, userInput);
        if (std::cin.eof()) {
            std::cin.clear();
            std::clearerr(stdin);
            std::cout << std::endl;
        } else if (userInput.empty()) {
            continue;
        } else if (userInput.compare("ADD") == 0) {
            if (myPhoneBook.addNewContact() == true) {
                std::cout << "Success" << std::endl;
            } else {
                std::cout << "Cancled" << std::endl;
            }
        } else if (userInput.compare("SEARCH") == 0) {
            myPhoneBook.printContactList();
            myPhoneBook.printSingleContactData();
        } else if (userInput.compare("EXIT") == 0) {
            break ;
        } else {
            std::cout << "Wrong command! [ADD, SEARCH, EXIT]" << std::endl;
        }
    }
    return 0;
}
