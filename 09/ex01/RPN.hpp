#pragma once

#ifndef RPN_H__
# define RPN_H__

# include <stack>
# include <string>
# include <iostream>

# define TOKEN_LIST "+-/*"

enum e_token_type {
    PLUS = 0,
    MINUS,
    DIVIDE,
    MULTIPLE
};

enum e_element_type {
 INVALID = 0,
 EMPTY,
 NUMBER,
 TOKEN
};

class RPN {
    private:
        const std::string _tokenList;
        std::stack<int> _stack;

        RPN(const RPN& src);
        RPN& operator= (const RPN& src);

    public:
        RPN(void);
        ~RPN();

        std::stack<int>::size_type getStackSize(void) const;
        const std::string cutSpace(const std::string originalExpression) const;
        int validateElement(const std::string target) const;
        void pushNumber(const std::string numberStr);
        bool handleToken(const std::string token);
        void calculate(const std::string originalExpression);

};

#endif
