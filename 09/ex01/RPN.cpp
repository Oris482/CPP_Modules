#include "RPN.hpp"
#include <string>

RPN::RPN(void): _tokenList(TOKEN_LIST){}

RPN::~RPN() {}

std::stack<int>::size_type RPN::getStackSize(void) const {
    return _stack.size();
}

const std::string RPN::cutSpace(const std::string originalExpression) const {
    std::string::size_type startPoint = 0;
    std::string::size_type endPoint = originalExpression.length() - 1;

    for (; startPoint < originalExpression.length(); ++startPoint) {
        if (originalExpression.at(startPoint) != ' ') break ;
    }
    for (; endPoint >= startPoint; --endPoint) {
        if (originalExpression.at(endPoint) != ' ') break ;
    }
    return originalExpression.substr(startPoint, endPoint - startPoint + 1);
}

int RPN::validateElement(const std::string target) const {
    if (target.length() == 0) return EMPTY;
    if (target.length() > 2) return INVALID;

    if (target.length() == 2) {
        const char sign = target.at(0);
        const char number = target.at(1);

        if (sign != '+' && sign != '-') return INVALID;
        if (number < '0' || number > '9') return INVALID;
        return NUMBER;
    } else {
        const char c = target.at(0);

        if (c >= '0' && c <= '9') return NUMBER;
        else if (_tokenList.find(c) != std::string::npos) return TOKEN;
        else return INVALID;
    }
}

void RPN::pushNumber(const std::string numberStr) {
    try {
        _stack.push(atoi(numberStr.c_str()));
    } catch (std::exception& e) {
        e.what();
        exit(1);
    }
}

bool RPN::handleToken(const std::string token) {
    if (getStackSize() < 2) return false;

    const int tokenType = _tokenList.find(token);

    int secondNum = _stack.top();
    _stack.pop();
    int firstNum = _stack.top();
    _stack.pop();

    switch (tokenType) {
        case PLUS:
            _stack.push(firstNum + secondNum);
            break ;

        case MINUS:
            _stack.push((firstNum - secondNum));
            break ;

        case DIVIDE:
            if (secondNum == 0) return false;
            _stack.push(firstNum / secondNum);
            break ;

        case MULTIPLE:
            _stack.push((firstNum * secondNum));
            break ;
    }
    return true;
}

void RPN::calculate(const std::string originalExpression) {
    const std::string cuttedExpression = cutSpace(originalExpression);
    std::string::size_type idx = 0;
    std::string::size_type startPoint = 0;

    while (idx <= cuttedExpression.length()) {
        if (idx != cuttedExpression.length() && cuttedExpression.at(idx) != ' ') {
            ++idx;
            continue ;
        }

        const std::string chunk = cuttedExpression.substr(startPoint, idx - startPoint);
        startPoint = idx + 1;
        const int elementType = validateElement(chunk);
        switch (elementType) {
            case EMPTY:
                break ;
                
            case INVALID:
                std::cout << "Error" << std::endl;
                exit(1);

            case NUMBER:
                pushNumber(chunk);
                break ;

            case TOKEN:
                handleToken(chunk);
                break ;
        }
        ++idx;
    }

    if (getStackSize() != 1) {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    std::cout << _stack.top() << std::endl;
}
