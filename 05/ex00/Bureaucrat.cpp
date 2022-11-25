/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/25 23:18:31 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
    
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade): _name(name), _grade(grade) {
    
}
