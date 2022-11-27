/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:03:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 18:32:17 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

bool RobotomyRequestForm::isRandomSeedCreated = false;

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
    // std::cout << "RobotomyRequestForm" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
    createRandomSeed();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name): Form(name, initialRequireSignGrade, initialRequireExecuteGrade) {
    // std::cout << "RobotomyRequestForm" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;   
    createRandomSeed();
}

void RobotomyRequestForm::createRandomSeed(void) {
    if (isRandomSeedCreated) return ;
    srand(time(NULL));
    isRandomSeedCreated = true;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) throw Form::NotSignedFormException;
    if (this->getGradeToExecute() < executor.getGrade()) throw Form::GradeTooLowException;

    if (rand() % 2 == 1) {
        std::cout << this->getName() << " is robotomized!" << std::endl;
    } else {
        std::cout << "* Something wrong...beep--beep-- *" << std::endl;
    }
}
