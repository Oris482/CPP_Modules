/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:58:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 20:17:58 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_H__
# define EASYFIND_H__

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, const int target) {
    typedef typename T::iterator iterator;

    iterator it;
    if (container.empty()) throw std::runtime_error("Empty container");
    it = std::find(container.begin(), container.end(), target);
    if (it == container.end()) throw std::runtime_error("Not Found");
    return it;
}

template <typename T>
void easyfindWrapper(T& container, const int target) {
    try {
        std::cout << *easyfind(container, target) << " is in container!" << std::endl;
    } catch (std::runtime_error& e) {
        std::cout <<"Error with finding " << target << ": " << e.what() << std::endl;
    }
}

#endif
