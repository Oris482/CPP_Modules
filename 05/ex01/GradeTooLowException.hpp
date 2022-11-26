/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:01:07 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/25 22:25:30 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#ifndef GRADETOOLOWEXCEPTION_H__
# define GRADETOOLOWEXCEPTION_H__ 

class GradeTooLowException: public std::exception {
    public:
        const char* what() const throw();
};

#endif
