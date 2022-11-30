/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:17:49 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 15:39:38 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void) {
    std::vector<int> intEmptyVec(0);
    std::vector<int> intVec(5);
    std::list<int> intEmptyList(0);
    std::list<int> intList(5);

    for (int i = 0; i < 5; i++) {
        intVec.push_back(i + 1);
        intList.push_back((i + 1));
    }

    easyfindWrapper(intEmptyVec, 3);
    easyfindWrapper(intVec, 3);
    easyfindWrapper(intVec, 5);
    easyfindWrapper(intVec, 6);
    std::cout << std::endl;
    
    easyfindWrapper(intEmptyList, 3);
    easyfindWrapper(intList, 3);
    easyfindWrapper(intList, 5);
    easyfindWrapper(intList, 6);
    return 0;
}
