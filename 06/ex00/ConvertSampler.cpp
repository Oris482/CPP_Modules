/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertSampler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:10:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 20:01:27 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cerrno>
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
        if (remain.compare("f") != SAME) throw ConvertSampler::InvalidInput;
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
    std::cout << this->getChar();
}

void ConvertSampler::printInt(void) const {
    std::cout << this->getInt();
}

void ConvertSampler::printFloat(void) const {
    std::cout << this->getFloat();
    if (this->getFloat() == 0) std::cout << ".0";
    std::cout << "f";
}

void ConvertSampler::printDouble(void) const {
    std::cout << this->getDouble();
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
