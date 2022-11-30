/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:06:54 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 18:31:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;    
    
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "------------------------------------" << std::endl;
    std::list<int> cloneList;
    
    cloneList.push_back(5);
    cloneList.push_back(17);
    std::cout << cloneList.back() << std::endl;
    cloneList.pop_back();
    std::cout << cloneList.size() << std::endl;
    std::cout << std::endl;
    cloneList.push_back(3);
    cloneList.push_back(5);
    cloneList.push_back(737);
    cloneList.push_back(0);
    std::list<int>::iterator listIt = cloneList.begin();
    std::list<int>::iterator listIte = cloneList.end();
    ++listIt;
    --listIt;
    while (listIt != listIte)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }
    std::cout << "------------------------------------" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    // original stack
    // std::stack<int>::iterator it = s.begin();
    // std::stack<int>::iterator ite = s.end();
    return 0;
}
