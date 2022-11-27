/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:39:39 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    {
        Form*   treeForm;
        Form*   runRobot;
        Form*   pardonBigBoss;
        Form*   trashForm;
        Intern  newbie;

        treeForm = newbie.makeForm("ShrubberyCreationForm", "Shrubbery : Gardening");
        std::cout << *treeForm << std::endl;

        runRobot = newbie.makeForm("RobotomyRequestForm", "Robotomy : Dyson");
        std::cout << *runRobot << std::endl;

        pardonBigBoss = newbie.makeForm("PresidentialPardonForm", "Pardon : Big_Boss");
        std::cout << *pardonBigBoss << std::endl;

        trashForm = newbie.makeForm("NotExistFormName", "Hello : Good");
        std::cout << trashForm << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        // sign: X / execute: X
        Bureaucrat staff("Staff", 150);

        // sign: treeForm / execute: X
        Bureaucrat manager("Manager", 140);

        // sign: treeForm, runRobot / execute: treeForm
        Bureaucrat director("Director", 70);

        // sign: treeForm, runRobot, pardonBigBoss / execute: treeForm, runRobot
        Bureaucrat president("President", 20);

        // sign: ALL / execute: ALL
        Bureaucrat king("king", 1);

        staff.executeForm(*treeForm);
        staff.signForm(*treeForm);           
        std::cout << std::endl;

        manager.executeForm(*treeForm);
        manager.signForm(*treeForm);
        manager.executeForm(*treeForm);
        std::cout << std::endl;

        director.executeForm(*treeForm);
        director.signForm(*runRobot);
        std::cout << std::endl;

        president.executeForm(*runRobot);
        president.executeForm(*runRobot);
        president.executeForm(*runRobot);
        president.executeForm(*runRobot);
        president.executeForm(*runRobot);
        std::cout << std::endl;

        president.signForm(*pardonBigBoss);
        king.executeForm(*pardonBigBoss);

        delete treeForm;
        delete runRobot;
        delete pardonBigBoss;

        system("leaks InternForm");
    }
    std::cout << "######################################################" << std::endl;

    return 0;
}
