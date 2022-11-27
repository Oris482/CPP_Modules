/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:50:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:25:27 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

#define FORM_NAME_TREE "ShrubberyCreationForm"
#define FORM_NAME_ROBOT "RobotomyRequestForm"
#define FORM_NAME_PARDON "PresidentialPardonForm"
#define FORM_COUNT 3
#define SAME 0

enum e_FormIndex {
    E_TREE = 0,
    E_ROBOT,
    E_PARDON
};

const std::runtime_error Intern::WrongFormName("Unvaild Form Name");

Intern::Intern(void) {
    // std::cout << "Intern" << " " << "default" << MSG_CONSTRUCTOR << std::endl;
}

Intern::~Intern(void) {
    // std::cout << "Intern" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

void Intern::printFormErrorReason(const std::string formName, const std::string action, const std::string reason) const {
    std::cout << "Intern couldn’t "
            << action
            << " <" 
            << formName
            << "> : "
            << reason
            << std::endl;
}

Form* Intern::makeForm(const std::string formName, const std::string formTarget) {
    const std::string formList[FORM_COUNT] = {FORM_NAME_TREE, FORM_NAME_ROBOT, FORM_NAME_PARDON};
    try {
        for (int i = 0; i < FORM_COUNT; ++i) {
            if (formName.compare(formList[i]) == SAME) {
                std::cout << "Intern creates <" << formName << "> - " << formTarget << std::endl; 
                switch (i) {
                    case E_TREE:
                        return new ShrubberyCreationForm(formTarget);
                        break ;
                    case E_ROBOT:
                        return new RobotomyRequestForm(formTarget);
                        break ;
                    case E_PARDON:
                        return new PresidentialPardonForm(formTarget);
                        break ;
                }
            }
        }
        throw WrongFormName;
    } catch (std::exception &e) {
        printFormErrorReason(formName, "create", e.what());
        return NULL;
    }
}
