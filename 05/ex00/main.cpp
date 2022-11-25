/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:07:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/25 22:26:27 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
    try {
        throw GradeTooHighException();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
