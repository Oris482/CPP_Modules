/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:39 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/30 18:32:46 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_H__
# define SPAN_H__

# include <vector>
# include <stdexcept>

class Span {
    typedef std::vector<int>::iterator iterator;

    private:
        unsigned int _size;
        std::vector<int> _intVec;
        static const std::runtime_error CapacityFull;
        static const std::out_of_range NotEnoughElements;
        
    public:
        Span(void);
        ~Span(void);
        Span(const Span& src);
        Span& operator= (const Span& src);

        Span(const unsigned int size);
        
        unsigned int getFreeSpace(void) const;
        void addNumber(const unsigned int num);
        void addNumber(const unsigned int start, const unsigned int end);
        void addNumber(iterator begin, iterator end);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;  
};

#endif
