/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 22:30:53 by jaesjeon         ###   ########.fr       */
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
        ShrubberyCreationForm treeForm("Plant_tree");
        RobotomyRequestForm runRobot("Run_Robotomy");
        PresidentialPardonForm pardonBigBoss("Pardon_Big_Boss");

        std::cout << treeForm << std::endl;
        std::cout << runRobot << std::endl;
        std::cout << pardonBigBoss << std::endl;

        Bureaucrat staff("Staff", 130);
        Bureaucrat manager("Manager", 100);
        Bureaucrat director("Director", 70);
        Bureaucrat president("President", 40);
        Bureaucrat king("king", 1);

        king.executeForm(treeForm);
        king.signForm(treeForm);
        king.executeForm(treeForm);
              
    }
    std::cout << "######################################################" << std::endl;

    return 0;
}
