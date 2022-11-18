/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:05 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/18 16:50:00 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Only one argument!" << std::endl;
        return 1;
    }
    Harl assistant;

    assistant.complain(argv[1]);
    return 0;
}
