/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:59 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 17:43:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>

const std::runtime_error Span::CapacityFull("No more space in this container");
const std::out_of_range Span::NotEnoughElements("There is less than 2 elements");

Span::Span(void): _size(0), _intVec() {}

Span::~Span(void) {}

Span::Span(const Span& src): _size(src._size), _intVec() {
    if (this->_size) {
        std::copy(src._intVec.begin(), src._intVec.end(), std::back_inserter(this->_intVec));
    }
}

Span& Span::operator=(const Span &src) {
    if (this != &src) {
        Span temp = src;
        std::swap(this->_size, temp._size);
        std::swap(this->_intVec, temp._intVec);
    }

    return *this;
}

Span::Span(const unsigned int num): _size(num), _intVec() {}

unsigned int Span::getFreeSpace(void) const {
    return (this->_size - this->_intVec.size());
}

void Span::addNumber(const unsigned int num) {
    if (this->getFreeSpace() == 0) throw Span::CapacityFull;

    this->_intVec.push_back(num);
}

void Span::addNumber(iterator begin, iterator end) {
    if (this->getFreeSpace() < std::distance(begin, end)) throw Span::CapacityFull;

    iterator it = begin;
    for (; it != end; ++it) {
        this->_intVec.push_back(*it);
    }
}

unsigned int Span::shortestSpan(void) const {
    if (this->_intVec.size() < 2) throw Span::NotEnoughElements;
    
    std::vector<int> temp = this->_intVec;
    std::sort(temp.begin(), temp.end());
    iterator it = temp.begin();
    int shortest = *(it + 1) - *it;
    ++it;
    while ((it + 1) != temp.end()) {
        int span = *(it + 1) - *it;
        if (span < shortest) shortest = span;
        ++it;
    }
    return shortest;
}

unsigned int Span::longestSpan(void) const {
    if (this->_intVec.size() < 2) throw Span::NotEnoughElements;

   int min = *std::min_element(this->_intVec.begin(), this->_intVec.end());
   int max = *std::max_element(this->_intVec.begin(), this->_intVec.end());
   return (max - min);
}
