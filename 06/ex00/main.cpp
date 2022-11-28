/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:49:39 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/28 14:25:19 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertSampler.hpp"

int main(int argc, char *argv[]) {
    ConvertSampler converter;

    if (argc != 2) return 1;
    
    converter.input(argv[1]);
    converter.printSampler();
    return 0;
}
