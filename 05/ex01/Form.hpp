/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:14:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 19:14:37 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#ifndef FORM_H__
# define FORM_H__

# include <string>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class Bureaucrat;

class Form {
    private:
        Form(void);
        
        const std::string _name;
        bool _isSigned;
        const unsigned int _gradeToSign;
        const unsigned int _gradeToExecute;

        static const unsigned int maxGrade = 1;
        static const unsigned int minGrade = 150;
        static const GradeTooHighException GradeTooHighException;
        static const GradeTooLowException GradeTooLowException;

    public:
        ~Form(void);
        Form(const Form &src);
        Form& operator= (const Form &src);

        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
    
        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        unsigned int getGradeToSign(void) const;
        unsigned int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &manager);
};

std::ostream& operator<< (std::ostream& os, const Form &target);

#endif
