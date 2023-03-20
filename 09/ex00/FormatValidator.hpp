#pragma once

#ifndef FORMATVALIDATOR_HPP
# define FORMATVALIDATOR_HPP

# include <string>
# include <errno.h>

struct FormatValidator {
    static bool isNumber(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isValidYear(int year);
    static bool isValidMonth(int month);
    static bool isValidDay(int year, int month, int day);

    static bool isValidDate(const std::string& date);
};

#endif
