/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:03:51 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 22:18:49 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void) {
    // std::cout << "RobotomyRequestForm" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
    // std::cout << "RobotomyRequestForm" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name): Form(name, initialRequireSignGrade, initialRequireExecuteGrade) {
    // std::cout << "RobotomyRequestForm" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;   
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) throw Form::NotSignedFormException;
    if (this->getGradeToExecute() < executor.getGrade()) throw Form::GradeTooLowException;
}
