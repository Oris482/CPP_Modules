/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:39:00 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 22:02:44 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_H__
# define ITER_H__

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

#endif
