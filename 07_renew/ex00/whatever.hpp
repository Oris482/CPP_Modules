/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:13:23 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 21:55:44 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>

#include <iostream>

template <typename T>
void swap(T* first, T* second) {
    T temp;

    std::cout << "여기에 들어옴 (1) " << (long)first << ", " << (long)second << std::endl;
    temp = *first;
    *first = *second;
    *second = temp;
}

template <typename T>
void swap(T& first, T& second) {

    std::cout << "여기에 들어옴 (2)" << std::endl;
    T temp = first; // copy constructor
    first = second; //assign operator
    second = temp; //assign operator
}

template <typename T>
const T& min(const T& first, const T& second) {
    if (first < second) return first;
    return second;
}

template <typename T>
const T& max(const T& first, const T& second) {
    if (first > second) return first;
    return second;
}
