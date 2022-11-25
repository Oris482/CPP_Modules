/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:20 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/25 23:17:19 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_H__
# define BUREAUCRAT_H__

# include <string>
# include "GradeTooHighException.hpp"
# include "GradeTooHighException.hpp"

class Bureaucrat {
    private:
        Bureaucrat(void);
        const std::string _name;
        unsigned int _grade;
        static const std::exception GradeTooHighException;
        static const std::exception GradeTooLowException;

    public:
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat& operator= (const  Bureaucrat &src);

        Bureaucrat(const std::string name, const unsigned int grade);

        std::string getName(void) const;
        unsigned int getGrade(void) const;
};

#endif
