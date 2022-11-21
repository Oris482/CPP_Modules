/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:27:12 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/22 00:34:49 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void): _newestIdeaIdx(NUM_EMPTY) {
    std::cout << "Brain" << " " << "Default" << MSG_CONSTRUCTOR << std::endl;
}

Brain::~Brain(void) {
    std::cout << "Brain" << " " << "Default" << MSG_DESTRUCTOR << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain" << " " << "Copy" << MSG_CONSTRUCTOR << std::endl;
    *this = src;
}

Brain& Brain::operator= (const Brain &src) {
    std::cout << "Brain" << " " << "Copy assignment" << MSG_OPERATOR << std::endl;
    for (int i = 0; i <= src.getNewestIdeaIdx(); ++i) {
        this->addSingleIdea(src.getSingleIdea(i));
    }
    return *this;
}

int Brain::getBrainCapacity(void) {
    return brainCapacity;
}

int Brain::getNewestIdeaIdx(void) const {
    return this->_newestIdeaIdx;
}

std::string Brain::getSingleIdea(const int idx) const {
    if (idx > this->getNewestIdeaIdx()) {
        std::cout << "I have no " << idx << ".idea." << std::endl;
        return NULL;
    }
    
    return this->_ideas[idx];
}

void Brain::addSingleIdea(const std::string idea) {
    if (this->getNewestIdeaIdx() == getBrainCapacity()) {
        std::cout << "Brain is full!" << std::endl;
        return ;
    }
    
    ++this->_newestIdeaIdx;
    this->_ideas[this->_newestIdeaIdx] = idea;
}

void Brain::printAllIdeas(void) const {
    if (this->getNewestIdeaIdx() == NUM_EMPTY) {
        std::cout << "Brain is empty" << std::endl;
        return ;
    }
    
    for (int i = 0; i <= this->getNewestIdeaIdx(); ++i) {
        std::cout << "Idea " << i << ".: " << this->getSingleIdea(i) << std::endl;
    }
}
