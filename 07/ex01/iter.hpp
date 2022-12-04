/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:39:00 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/12/04 19:21:16 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_H__
# define ITER_H__

# include <iostream>

template <typename T>
void iter(T* array, unsigned int length, void (*f)(T&)) {
    for (unsigned int i = 0; i < length; ++i) {
        f(array[i]);
    }
}

template <typename T>
void iter(const T* array, unsigned int length, void (*f)(const T&)) {
    for (unsigned int i = 0; i < length; ++i) {
        f(array[i]);
    }
}

template <typename T>
void plusOne(T& target) {
    target += 1;
}

template <typename T>
void printAll(const T& target) {
    std::cout << target << std::endl;
}


#endif
