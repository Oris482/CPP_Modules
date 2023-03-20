#pragma once

#ifndef STRINGSPLITER_H__
# define STRINGSPLITER_H__

# include <string>

# define INPUT_DELIMITER " | "
# define CSV_DELIMITER ","

class StringSpliter {
    private:
        bool _successFlag;
        std::string _targetStr;
        const std::string _delimiter;
        std::string _frontStr;
        std::string _backStr;

        StringSpliter(void);
        StringSpliter(const StringSpliter& src);
        StringSpliter& operator= (const StringSpliter& src);
    
    public:
        ~StringSpliter();
        StringSpliter(std::string target, const std::string& delimiter);

        bool getSuccessFlag(void) const;
        std::string getFrontStr(void) const;
        std::string getBackStr(void) const;

        void split(void);
};

#endif
