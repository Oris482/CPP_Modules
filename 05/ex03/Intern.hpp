/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:50:14 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:25:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_H__
# define INTERN_H__

# include <stdexcept>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define MSG_CONSTRUCTOR " constructor called"
# define MSG_DESTRUCTOR " destructor called"
# define MSG_OPERATOR " operator called"

class Intern {
    private:
        Intern(const Intern &src);
        Intern& operator= (const Intern &src);
        
        static const std::runtime_error WrongFormName;
        void printFormErrorReason(const std::string formName, const std::string action, const std::string reason) const;
    
    public:
        Intern(void);
        ~Intern(void);

        Form* makeForm(const std::string formName, const std::string formTarget);
};

#endif
