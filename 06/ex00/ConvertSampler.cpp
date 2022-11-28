/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertSampler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:10:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/28 19:57:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cerrno>
#include <cmath>
#include <climits>
#include "ConvertSampler.hpp"

#define SAME 0

const std::out_of_range ConvertSampler::OutOfRange("Out of range");
const std::runtime_error ConvertSampler::InvalidInput("Invalid input");

ConvertSampler::ConvertSampler(void): _convertedChar(0), _convertedInt(0), \
                                        _convertedFloat(0), _convertedDouble(0) {}

ConvertSampler::~ConvertSampler(void) {}

ConvertSampler::ConvertSampler(const ConvertSampler &src) {
    *this = src;
}

ConvertSampler& ConvertSampler::operator= (const ConvertSampler &src) {
    this->_convertedChar = src.getChar();
    this->_convertedInt = src.getInt();
    this->_convertedFloat = src.getFloat();
    this->_convertedDouble = src.getDouble();
    return *this;
}

ConvertSampler::ConvertSampler(const char *argv) {
    this->input(argv);
}

char ConvertSampler::getChar(void) const {
    return this->_convertedChar;
}

int ConvertSampler::getInt(void) const {
    return this->_convertedInt;
}

float ConvertSampler::getFloat(void) const {
    return this->_convertedFloat;
}

double ConvertSampler::getDouble(void) const {
    return this->_convertedDouble;
}

bool ConvertSampler::getRangeErrorFlag(void) const {
    return this->_outOfRangeFlag;
}

bool ConvertSampler::getInputErrorFlag(void) const {
    return this->_invalidInputFlag;
}

void ConvertSampler::input(const char *argv) {
    double convertedValue;
    char*   tempRemainStr = NULL;
    
    try {
        convertedValue = std::strtod(argv, &tempRemainStr);
        if (errno == ERANGE) {
            errno = 0;
            throw ConvertSampler::OutOfRange;
        }
        std::string remain = static_cast<std::string>(tempRemainStr);
        if (remain.length() > 1) throw ConvertSampler::InvalidInput;

        std::string input = static_cast<std::string>(argv);
        if (input.length() == 1 && remain.length() == 1) convertedValue = static_cast<double>(argv[0]);
    }
    catch (std::out_of_range &e) {
        this->_outOfRangeFlag = true;
        return ;
    }
    catch (std::runtime_error &e) {
        this->_invalidInputFlag = true;
        return ;
    }

    this->_convertedChar = static_cast<char>(convertedValue);
    this->_convertedInt = static_cast<int>(convertedValue);
    this->_convertedFloat = static_cast<float>(convertedValue);
    this->_convertedDouble = static_cast<double>(convertedValue);
}

void ConvertSampler::printChar(void) const {
    if (this->getDouble() >= 0 && this->getDouble() <= 31)
        std::cout << "Non displayable";
    else if (this->getDouble() < 0 || this->getDouble() > 127)
        std::cout << "impossible";
    else {
        switch (this->getChar()) {
            case 127:
                std::cout << "<DEL>";
                break ;
            default:
                std::cout << "'" << this->getChar() << "'";
        }
    }
}

void ConvertSampler::printInt(void) const {
    if (this->getDouble() > INT_MAX || this->getDouble() < INT_MIN)
        std::cout << "impossible";
    else
        std::cout << this->getInt();
}

void ConvertSampler::printFloat(void) const {
    if (isnan(this->getFloat()) || isinf(this->getFloat())) {
        std::cout << std::showpos << this->getFloat() << "f";
    } else if (this->getFloat() == static_cast<int>(this->getFloat())) {
        std::cout << this->getFloat() << ".0f";
    } else {
        std::cout << this->getFloat() << "f";
    }
}

void ConvertSampler::printDouble(void) const {
    std::stringstream ss;
    std::string convertedToStr;
    
    ss << getDouble();
    ss >> convertedToStr;
    if (convertedToStr.compare("nan") == SAME || convertedToStr.compare("inf") == SAME) {
        std::cout << std::showpos << this->getDouble();
    }
    else if (this->getDouble() == static_cast<int>(this->getDouble())) {
        std::cout << this->getDouble() << ".0";
    } else {
        std::cout << this->getDouble();
    }

}

void ConvertSampler::printSampler(void) const {
    if (this->getRangeErrorFlag()) {
        std::cout << "ERROR: Out of range" << std::endl;
        return ;
    } else if (this->getInputErrorFlag()) {
        std::cout << "ERROR: Invalid input" << std::endl;
        return ;
    }

    std::cout << "char: ";
    this->printChar();
    std::cout << std::endl;
    std::cout << "int: ";
    this->printInt();
    std::cout << std::endl;
    std::cout << "float: ";
    this->printFloat();
    std::cout << std::endl;
    std::cout << "double: ";
    this->printDouble();
    std::cout << std::endl;
}
