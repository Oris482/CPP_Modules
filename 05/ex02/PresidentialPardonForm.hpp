/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:02:56 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 17:41:46 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_H__
# define PRESIDENTIALPARDONFORM_H__

# include "Form.hpp"

class PresidentialPardonForm: public Form {
    private:
        PresidentialPardonForm(void);
        PresidentialPardonForm& operator= (const PresidentialPardonForm &src);

        static const unsigned int initialRequireSignGrade = 25;
        static const unsigned int initialRequireExecuteGrade = 5;
    
    public:
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm &src);

        explicit PresidentialPardonForm(const std::string name);

        void execute(Bureaucrat const &executor) const;
};

#endif
