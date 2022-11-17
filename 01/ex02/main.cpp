/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:42:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 13:51:35 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    std::string staticString = "HI THIS IS BRAIN";
    std::string *stringPTR = &staticString;
    std::string &stringREF = staticString;

    std::cout << "Check Address" << std::endl;
    std::cout << "staticString\t:\t" << &staticString << std::endl;
    std::cout << "stringPTR\t:\t" << &stringPTR << std::endl;
    std::cout << "stringREF\t:\t" << &stringREF << std::endl;

    std::cout << "Check Value" << std::endl;
    std::cout << "staticString\t:\t" << staticString << std::endl;
    std::cout << "stringPTR\t:\t" << stringPTR << std::endl;
    std::cout << "stringREF\t:\t" << stringREF << std::endl;

    return 0;
}
