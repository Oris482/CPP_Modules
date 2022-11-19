/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:57:23 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:59:48 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H__
# define HARL_H__

enum functionIndex {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    EXCEPTION = 4
};

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void exception(void);
        void (Harl::*harlFunc[5])(void);
        
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
};

#endif
