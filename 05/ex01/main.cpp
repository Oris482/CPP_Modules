/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 21:03:46 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    // initial grade exception error
    {
        // Form failForm("exception", 0, 30);
        // Form failForm("exception", 30, 151);
        // Form failForm("exception", 256, -256);
    }

    {
        Form buySomePencil("Buy some pencil", 120, 100);
        Form rentCar("Lent car", 80, 60);
        Form buildBuilding("Built building", 60, 40);

        Bureaucrat staff("Staff", 130);
        Bureaucrat manager("Manager", 100);
        Bureaucrat director("Director", 70);
        Bureaucrat president("President", 40);

        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << buySomePencil << std::endl;
        staff.signForm(buySomePencil);
        manager.signForm(buySomePencil);
        std::cout << "-----------------------------------------------------" << std::endl;

        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << rentCar << std::endl;
        manager.signForm(rentCar);
        director.signForm(rentCar);
        std::cout << "-----------------------------------------------------" << std::endl;
        
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << buildBuilding << std::endl;
        director.signForm(buildBuilding);
        president.signForm(buildBuilding);        
        std::cout << "-----------------------------------------------------" << std::endl;
        president.signForm(buySomePencil);        
        president.signForm(rentCar);        
        president.signForm(buildBuilding);        
    }
    std::cout << "######################################################" << std::endl;
    {
        Form buySomePencil("Buy some pencil", 120, 100);
        Form buySomeEraser("Buy some eraser", 1, 1);
        
        std::cout << buySomePencil << std::endl;
        std::cout << buySomeEraser << std::endl;

        buySomeEraser = buySomePencil;
        std::cout << buySomeEraser << std::endl;
    }
    return 0;
}
