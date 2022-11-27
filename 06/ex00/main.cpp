/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:49:39 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 20:02:42 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertSampler.hpp"

int main(void) {
    ConvertSampler converter;

    converter.input("150");
    converter.printSampler();
    return 0;
}
