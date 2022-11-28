/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:50:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 03:01:09 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MasterBox.hpp"

int main(void) {
    MasterBox masterBox;
    Base*   basePTR;

    basePTR = masterBox.generate();
    masterBox.identify(basePTR);
    delete basePTR;

    basePTR = masterBox.generate();
    masterBox.identify(basePTR);
    delete basePTR;

    basePTR = masterBox.generate();
    masterBox.identify(basePTR);
    delete basePTR;

    std::cout << "----------------------------------------------" << std::endl;

    basePTR = masterBox.generate();
    masterBox.identify(*basePTR);
    delete basePTR;

    basePTR = masterBox.generate();
    masterBox.identify(*basePTR);
    delete basePTR;

    basePTR = masterBox.generate();
    masterBox.identify(*basePTR);
    delete basePTR;

    return 0;
}
