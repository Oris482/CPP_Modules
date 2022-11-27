/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:20 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 16:59:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_H__
# define BUREAUCRAT_H__

# include <string>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class Form;

class Bureaucrat {
    private:
        Bureaucrat(void);

        const std::string _name;
        unsigned int _grade;
        void printFormErrorReason(const std::string formName, const std::string action, const std::string reason) const;
        
        static const unsigned int maxGrade = 1;
        static const unsigned int minGrade = 150;
        static const GradeTooHighException GradeTooHighException;
        static const GradeTooLowException GradeTooLowException;

    public:
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat& operator= (const  Bureaucrat &src);

        explicit Bureaucrat(const std::string name, const int grade);

        const std::string& getName(void) const;
        unsigned int getGrade(void) const;
        void promote(void);
        void demote(void);
        void signForm(Form &form) const;
};

std::ostream& operator<< (std::ostream &os, const Bureaucrat &target);

#endif
