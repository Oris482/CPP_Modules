/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:27:10 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/21 23:58:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_H__
# define BRAIN_H__

# include <string>

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"
# define NUM_EMPTY -1

class Brain {
    private:
        static const int brainCapacity = 100;
        std::string _ideas[brainCapacity];
        int _newestIdeaIdx;
    
    public:
        Brain(void);
        ~Brain(void);
        Brain(const Brain &src);
        Brain& operator= (const Brain &src);

        static int getBrainCapacity(void);
        int getNewestIdeaIdx(void) const;
        std::string getSingleIdea(const int idx) const;
        void addSingleIdea(const std::string idea);
        void printAllIdeas(void) const;
};

#endif
