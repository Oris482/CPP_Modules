/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtString.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:51:56 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/20 14:44:44 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtString.hpp"

FtString::FtString(void): _str(""), _length(0) {}

FtString::FtString(std::string initialString): _str(initialString), _length(initialString.length()) {}

FtString::~FtString(void) {}

std::string FtString::value(void) const {
    return this->_str;
}

std::string::size_type FtString::length(void) const {
    return this->_length;
}

void FtString::assign(std::string str) {
    this->_str = str;
    this->_length = str.length();
}

void FtString::replace(const std::string s1, const std::string s2) {
    const std::string::size_type destChunkLength = s1.length();
    if (destChunkLength == 0) return ;
    const std::string::size_type srcChunkLength = s2.length();
    const bool needShrink = destChunkLength > srcChunkLength;
    std::string::size_type prevFindIdx = 0;
    std::string::size_type findIdx = 0;
    std::string replacedString;

    replacedString.reserve(this->_length);
    while (true) {
        findIdx = this->_str.find(s1, prevFindIdx);
        if (findIdx == std::string::npos) break ;
        replacedString.append(this->_str.substr(prevFindIdx, findIdx - prevFindIdx));
        replacedString.append(s2);
        prevFindIdx = findIdx + destChunkLength;
    }
    replacedString.append(this->_str.substr(prevFindIdx));
    if (needShrink) replacedString.resize(replacedString.length());
    this->_str = replacedString;
    this->_length = this->_str.length();
}
