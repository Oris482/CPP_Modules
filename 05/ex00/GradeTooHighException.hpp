/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:01:05 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/25 22:14:22 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#ifndef GRADETOOHIGHEXCEPTION_H__
# define GRADETOOHIGHEXCEPTION_H__ 

class GradeTooHighException: public std::exception {
    public:
        const char* what() const throw();
};

#endif
