/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:17:03 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/15 20:31:58 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

#define MSG_NO_ARG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char *argv[])
{
    std::locale loc;
    int idx = 1;

    if (argc > 1) {
        while (idx < argc) {
            std::string str(argv[idx++]);
            for (std::string::size_type i = 0; i < str.length(); ++i)
                std::cout << std::toupper(str[i], loc);
        }
        std::cout << std::endl;
    }
    else
        std::cout << MSG_NO_ARG << std::endl;
    return 0;
}
