/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:13:23 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 18:36:35 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <utility>
#ifndef WHATEVER_H__
# define WHATEVER_H__

template <typename T>
void swap(T* first, T* second) {
    T temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

template <typename T>
void swap(T& first, T& second) {
    T temp;

    temp = first;
    first = second;
    second = temp;
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

#endif
