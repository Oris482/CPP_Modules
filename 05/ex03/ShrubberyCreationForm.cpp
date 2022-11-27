/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 18:33:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm" << " " << "default" << MSG_DESTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
    // std::cout << "ShrubberyCreationForm" << " " << "copy" << MSG_CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): Form(name, initialRequireSignGrade, initialRequireExecuteGrade) {
    // std::cout << "ShrubberyCreationForm" << " " << "argv" << MSG_CONSTRUCTOR << std::endl;   
}

bool ShrubberyCreationForm::plantTree(const std::string formName) {
    const std::string outFilename = formName + "_shrubbery";
    std::ofstream fout;
    fout.open(outFilename.c_str(), std::fstream::trunc);
    if (!fout.is_open()) return false;
    
    std::string referenceTree = "           *             ,\n"
                                "                       _/^\\_\n"
                                "                      <     >\n"
                                "     *                 /.-.\\         *\n"
                                "              *        `/&\\`                   *\n"
                                "                      ,@.*;@,\n"
                                "                     /_o.I %_\\    *\n"
                                "        *           (`'--:o(_@;\n"
                                "                   /`;--.,__ `')             *\n"
                                "                  ;@`o % O,*`'`&\\\n"
                                "            *    (`'--)_@ ;o %'()\\      *\n"
                                "                 /`;--._`''--._O'@;\n"
                                "                /&*,()~o`;-.,_ `\"\"`)\n"
                                "     *          /`,@ ;+& () o*`;-';\\\n"
                                "               (`\"\"--.,_0 +% @' &()\\\n"
                                "               /-.,_    ``''--....-'`)  *\n"
                                "          *    /@%;o`:;'--,.__   __.'\\\n"
                                "              ;*,&(); @ % &^;~` `o;@();         *\n"
                                "              /(); o^~; & ().o@*&`;&%O\\\n"
                                "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
                                "           __.----.(\\-''#####---...___...-----._\n"
                                "         '`         \\)_`\"\"\"\"\"`\n"
                                "                 .--' ')\n"
                                "               o(  )_-\\\n"
                                "                 `\"\"\"` `";
    fout << referenceTree;
    return true;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) throw Form::NotSignedFormException;
    if (this->getGradeToExecute() < executor.getGrade()) throw Form::GradeTooLowException;

    if (plantTree(this->getName()) == false) throw Form::FileOpenException;
}
