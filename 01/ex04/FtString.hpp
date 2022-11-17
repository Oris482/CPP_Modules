/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtString.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:51:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 17:01:29 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class FtString {
    private:
        std::string _str;
        std::string::size_type _length;
    
    public:
        FtString(void);
        explicit FtString(std::string initialString);
        ~FtString(void);
        std::string value(void) const;
        std::string::size_type length(void) const;
        void assign(std::string str);
        void replace(const std::string s1, const std::string s2);
};
