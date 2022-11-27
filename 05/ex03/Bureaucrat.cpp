/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 21:53:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::out_of_range Bureaucrat::GradeTooHighException("High Grade");
const std::out_of_range Bureaucrat::GradeTooLowException("Low Grade");
const std::runtime_error Bureaucrat::NotSignedFormException("Not Signed");
const std::runtime_error Bureaucrat::AlreadySignedFormException("Already Signed");

Bureaucrat::~Bureaucrat(void) {
    // std::cout << "Bureaucrat" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()) {
    // std::cout << "Bureaucrat" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
    // std::cout << "Bureaucrat" << " " << "assign" << MSG_OPERATOR << std::endl;
    this->_grade = src.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name) {
    // std::cout << "Bureaucrat" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;
    if (grade < (int)maxGrade) throw Bureaucrat::GradeTooHighException;
    if (grade > (int)minGrade) throw Bureaucrat::GradeTooLowException;
    
    this->_grade = grade;
}

const std::string& Bureaucrat::getName(void) const {
    return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void Bureaucrat::promote(void) {
    if (this->getGrade() == maxGrade) throw Bureaucrat::GradeTooHighException;

    --this->_grade;
}

void Bureaucrat::demote(void) {
    if (this->getGrade() == minGrade) throw Bureaucrat::GradeTooLowException;

    ++this->_grade;
}

void Bureaucrat::printFormErrorReason(const std::string formName, const std::string action, const std::string reason) const {
    std::cout << this->getName() 
            << " couldn’t "
            << action
            << " <" 
            << formName
            << "> : "
            << reason
            << std::endl;
}

void Bureaucrat::signForm(Form &form) const {
    try {form.beSigned(*this);}
    catch (std::exception &e) {
        printFormErrorReason(form.getName(), "sign", e.what());
        return ;
    }
    
    std::cout << this->getName() 
            << " signed <" 
            << form.getName() 
            << ">"
            << std::endl;
}

void Bureaucrat::executeForm(const Form &form) {
    try {form.execute(*this);}
    catch (std::exception &e) {
        printFormErrorReason(form.getName(), "execute", e.what());
        return ;
    }
    
    std::cout << this->getName() 
                << " executed <" 
                << form.getName() 
                << ">"
                << std::endl;
}

std::ostream& operator<< (std::ostream &os, const Bureaucrat &target) {
    os << target.getName() << ", bureaucrat grade  " << target.getGrade();
    return os;
}
