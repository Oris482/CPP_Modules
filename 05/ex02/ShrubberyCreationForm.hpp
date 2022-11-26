/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:32:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/26 22:43:04 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_H__
# define SHRUBBERYCREATIONFORM_H__

# include "Form.hpp"

class ShrubberyCreationForm: public Form {
    private:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm &src);

        static bool plantTree(const std::string formName);

        static const unsigned int initialRequireSignGrade = 145;
        static const unsigned int initialRequireExecuteGrade = 137;
    
    public:
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);

        ShrubberyCreationForm(const std::string name);

        void execute(Bureaucrat const &executor) const;
};

#endif
