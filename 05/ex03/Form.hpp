/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:14:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:30:59 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_H__
# define FORM_H__

# include <string>
# include <stdexcept>

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class Bureaucrat;

class Form {
    protected:
        Form(void);
        explicit Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        
        const std::string _name;
        bool _isSigned;
        const unsigned int _gradeToSign;
        const unsigned int _gradeToExecute;

        static const unsigned int maxGrade = 1;
        static const unsigned int minGrade = 150;
        static const std::out_of_range GradeTooHighException;
        static const std::out_of_range GradeTooLowException;
        static const std::runtime_error NotSignedFormException;
        static const std::runtime_error AlreadySignedFormException;
        static const std::runtime_error FileOpenException;

    public:
        virtual ~Form(void);
        Form(const Form &src);
        Form& operator= (const Form &src);

        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        unsigned int getGradeToSign(void) const;
        unsigned int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &manager);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<< (std::ostream& os, const Form &target);

#endif
