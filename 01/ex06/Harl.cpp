/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:57:26 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 21:00:41 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

#define MSG_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define MSG_INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define MSG_WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERROR "This is unacceptable! I want to speak to the manager now."
#define MSG_EXCEPTION "[ Probably complaining about insignificant problems ]"

Harl::Harl(void) {
    this->harlFunc[DEBUG] = &Harl::debug;
    this->harlFunc[INFO] = &Harl::info;
    this->harlFunc[WARNING] = &Harl::warning;
    this->harlFunc[ERROR] = &Harl::error;
    this->harlFunc[EXCEPTION] = &Harl::exception;
}

Harl::~Harl(void) {}

void Harl::debug(void) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << MSG_DEBUG << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout << MSG_INFO << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << MSG_WARNING << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << MSG_ERROR << std::endl;
}

void Harl::exception(void) {
    std::cout << MSG_EXCEPTION << std::endl;
}

void Harl::complain(std::string level) {
    const std::string commandList = "[DEBUG][INFO][WARNING][ERROR]";
    const std::string selectedCommand = "[" + level + "]";

    switch (commandList.find(selectedCommand))
    {
        case 0:
            (this->*harlFunc[0])();
        
        case 7:
            (this->*harlFunc[1])();
        
        case 13:
            (this->*harlFunc[2])();
        
        case 22:
            (this->*harlFunc[3])();
            break;
        
        default:
            (this->*harlFunc[4])();
            break;
    }
}
