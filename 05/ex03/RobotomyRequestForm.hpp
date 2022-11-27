/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:02:07 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 16:25:11 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_H__
# define ROBOTOMYREQUESTFORM_H__

# include "Form.hpp"

class RobotomyRequestForm: public Form {
    private:
        RobotomyRequestForm(void);
        RobotomyRequestForm& operator= (const RobotomyRequestForm &src);

        static void createRandomSeed(void);
        static bool isRandomSeedCreated;

        static const unsigned int initialRequireSignGrade = 72;
        static const unsigned int initialRequireExecuteGrade = 45;
    
    public:
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &src);

        RobotomyRequestForm(const std::string name);

        void execute(Bureaucrat const &executor) const;
};

#endif
