/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 16:40:56 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    // initial grade exception error
    {
        // Form failForm("exception", 0, 30);
        // Form failForm("exception", 30, 151);
        // Form failForm("exception", 256, -256);
    }

    {
        ShrubberyCreationForm treeForm("Shrubbery : Gardening");
        RobotomyRequestForm runRobot("Robotomy : Dyson");
        PresidentialPardonForm pardonBigBoss("Pardon : Big_Boss");

        std::cout << treeForm << std::endl;
        std::cout << runRobot << std::endl;
        std::cout << pardonBigBoss << std::endl;

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

        staff.executeForm(treeForm);
        staff.signForm(treeForm);           
        std::cout << std::endl;

        manager.executeForm(treeForm);
        manager.signForm(treeForm);
        manager.executeForm(treeForm);
        std::cout << std::endl;

        director.executeForm(treeForm);
        director.signForm(runRobot);
        std::cout << std::endl;

        president.executeForm(runRobot);
        president.executeForm(runRobot);
        president.executeForm(runRobot);
        president.executeForm(runRobot);
        president.executeForm(runRobot);
        std::cout << std::endl;

        president.signForm(pardonBigBoss);
        king.executeForm(pardonBigBoss);
    }
    std::cout << "######################################################" << std::endl;

    return 0;
}
