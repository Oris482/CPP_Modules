/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 15:54:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"

const GradeTooHighException Bureaucrat::GradeTooHighException;
const GradeTooLowException Bureaucrat::GradeTooLowException;

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()) {
    std::cout << "Bureaucrat" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
    std::cout << "Bureaucrat" << " " << "assign" << MSG_OPERATOR << std::endl;
    this->_grade = src.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade): _name(name), _grade(grade) {
    std::cout << "Bureaucrat" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;
}

std::string Bureaucrat::getName(void) const {
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

std::ostream& operator<< (std::ostream &os, const Bureaucrat &target) {
    os << target.getName() << ", bureaucrat grade  " << target.getGrade() << ".";
    return os;
}
