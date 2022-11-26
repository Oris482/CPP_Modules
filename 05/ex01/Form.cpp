/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:14:55 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 20:56:34 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <ostream>
#include <stdlib.h>

const GradeTooHighException Form::GradeTooHighException;
const GradeTooLowException Form::GradeTooLowException;

Form::~Form(void) {
    // std::cout << "Form" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

Form::Form(const Form &src): _name(src.getName()), _gradeToSign(src.getGradeToSign()), \
                                                    _gradeToExecute(src.getGradeToExecute()) {
    // std::cout << "Form" << " " << "copy" << MSG_DESTRUCTOR << std::endl;
    *this = src;
}

Form& Form::operator=(const Form &src) {
    // std::cout << "Form" << " " << "assign" << MSG_OPERATOR << std::endl;
    const_cast<unsigned int&>(this->_gradeToSign) = src.getGradeToSign();
    const_cast<unsigned int&>(this->_gradeToExecute) = src.getGradeToExecute();
    
    return *this;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), \
                                                            _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    // std::cout << "Form" << " " << "argv" << MSG_DESTRUCTOR << std::endl;
    if (gradeToSign < (int)maxGrade || gradeToExecute < (int)maxGrade) throw Form::GradeTooHighException;
    if (gradeToSign > (int)minGrade || gradeToExecute > (int)minGrade) throw Form::GradeTooLowException;
}

const std::string& Form::getName(void) const {
    return this->_name;
}

bool Form::getIsSigned(void) const {
    return this->_isSigned;
}

unsigned int Form::getGradeToSign(void) const {
    return this->_gradeToSign;
}

unsigned int Form::getGradeToExecute(void) const {
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &manager) {
    if (this->getGradeToSign() < manager.getGrade()) throw Form::GradeTooLowException;
    
    this->_isSigned = true;
}

std::ostream& operator<< (std::ostream& os, const Form& target) {
    os << "Form name: " << target.getName() << "\n"
        << "Signed: " << target.getIsSigned() << "\n"
        << "Grade to sign: " << target.getGradeToSign() << "\n"
        << "Grade to execute: " << target.getGradeToExecute() << std::endl;
    return os;
}
