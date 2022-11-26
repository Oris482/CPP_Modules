/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:03:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 22:18:52 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void) {
    // std::cout << "PresidentialPardonForm" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
    // std::cout << "PresidentialPardonForm" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name): Form(name, initialRequireSignGrade, initialRequireExecuteGrade) {
    // std::cout << "PresidentialPardonForm" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;   
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) throw Form::NotSignedFormException;
    if (this->getGradeToExecute() < executor.getGrade()) throw Form::GradeTooLowException;
}
