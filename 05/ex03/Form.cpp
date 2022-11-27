/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:14:55 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:38:30 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <ostream>
#include <stdexcept>
#include <stdlib.h>

const std::out_of_range Form::GradeTooHighException("High Grade");
const std::out_of_range Form::GradeTooLowException("Low Grade");
const std::runtime_error Form::NotSignedFormException("Not Signed");
const std::runtime_error Form::AlreadySignedFormException("Already Signed");
const std::runtime_error Form::FileOpenException("Fail to open file");

Form::~Form(void) {
    std::cout << "Form" << " " << "default" << MSG_DESTRUCTOR << std::endl;
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
    if (this->getIsSigned()) throw Form::AlreadySignedFormException;
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
