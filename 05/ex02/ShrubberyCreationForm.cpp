/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 22:58:42 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <__tuple>
#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    // std::cout << "ShrubberyCreationForm" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
    // std::cout << "ShrubberyCreationForm" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): Form(name, initialRequireSignGrade, initialRequireExecuteGrade) {
    // std::cout << "ShrubberyCreationForm" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;   
}

bool ShrubberyCreationForm::plantTree(const std::string formName) {
    const std::string inFilename = "ReferenceTree";
    const std::string outFilename = formName + "_shrubbery";
    std::ifstream fin;
    std::ofstream fout;
    fin.open(inFilename.c_str());
    fout.open(outFilename.c_str(), std::fstream::trunc);
    if (!fin.is_open() || !fout.is_open()) {
        if (fout.is_open()) std::remove(outFilename.c_str());
        return false;
    }
    
    std::string line;
    while (fin.good()) {
        std::getline(fin, line);
        if (!fin.eof() && fin.fail()) {
            std::remove(outFilename.c_str());
            return false;
        }
        fout << line << "\n";
        line.clear();
    }
    return true;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) throw Form::NotSignedFormException;
    if (this->getGradeToExecute() < executor.getGrade()) throw Form::GradeTooLowException;

    if (plantTree(this->getName()) == false) throw Form::FileOpenException;
}
