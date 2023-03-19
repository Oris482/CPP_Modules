#include "FormatValidator.hpp"
#include "StringSpliter.hpp"

#define DATE_SEPARATOR "-"

bool FormatValidator::isNumber(const std::string& str) {
    const char *c = str.c_str();

    while (*c) {
        if (*c < '0' || *c > '9') return false;
        ++c;
    }
    return true;
}

bool FormatValidator::isFloat(const std::string& str) {
    char *pEnd;

    strtof(str.c_str(), &pEnd);
    if (errno == ERANGE || *pEnd != '\0') {
        errno = 0;
        return false;
    }
    return true;
}

bool FormatValidator::isValidYear(int year) {
    if (year < 1500 || year > 9999) return false;

    return true;
}

bool FormatValidator::isValidMonth(int month) {
    if (month < 1 || month > 12) return false;

    return true;
}

bool FormatValidator::isValidDay(int year, int month, int day) {
    int maxDay;
    const bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

    if (month < 8) {
        // 2
        if (month == 2) {
            maxDay = isLeapYear ? 29 : 28;
        } else {
            // 4, 6
            if (month % 2 == 0) {
                maxDay = 30;
            // 1, 3, 5, 7
            } else {
                maxDay = 31;
            }
        }
    } else {
        // 8, 10, 12
        if (month % 2 == 0) {
            maxDay = 31;
        // 9, 11
        } else {
            maxDay = 30;
        }
    }
    return (day > 0 && day <= maxDay);
}

bool FormatValidator::isValidDate(const std::string& date) {
    StringSpliter yearSpliter(date, DATE_SEPARATOR);
    int year, month, day;

    if (!yearSpliter.getSuccessFlag()
        || yearSpliter.getFrontStr().length() != 4
        || !isNumber(yearSpliter.getFrontStr())) return false;
    year = atoi(yearSpliter.getFrontStr().c_str());

    StringSpliter leftSpliter(yearSpliter.getBackStr(), DATE_SEPARATOR);
    if (!leftSpliter.getSuccessFlag()
        || leftSpliter.getFrontStr().length() != 2
        || leftSpliter.getBackStr().length() != 2
        || !isNumber(leftSpliter.getFrontStr())
        || !isNumber(leftSpliter.getBackStr())) return false;
    month = atoi(leftSpliter.getFrontStr().c_str());
    day = atoi(leftSpliter.getBackStr().c_str());

    if (!isValidYear(year) || !isValidMonth(month)) return false;
    return (isValidDay(year, month, day));
}
