/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:12:20 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 15:37:11 by jaesjeon         ###   ########.fr       */
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

class Bureaucrat {
    private:
        Bureaucrat(void);
        const std::string _name;
        unsigned int _grade;
        static const unsigned int maxGrade = 1;
        static const unsigned int minGrade = 150;
        static const GradeTooHighException GradeTooHighException;
        static const GradeTooLowException GradeTooLowException;

    public:
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat& operator= (const  Bureaucrat &src);

        Bureaucrat(const std::string name, const unsigned int grade);

        std::string getName(void) const;
        unsigned int getGrade(void) const;
        void promote(void);
        void demote(void);
};

std::ostream& operator<< (std::ostream &os, const Bureaucrat &target);

#endif
