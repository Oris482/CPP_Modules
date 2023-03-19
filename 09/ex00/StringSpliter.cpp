#include "StringSpliter.hpp"

StringSpliter::StringSpliter(std::string target, const std::string& delimeter): _successFlag(false), _targetStr(target), _delimiter(delimeter) {
    split();
}

StringSpliter::~StringSpliter() {}

void StringSpliter::split(void) {
    const std::size_t foundPos = _targetStr.find(_delimiter);

    if (foundPos == std::string::npos) return ;

    _frontStr = _targetStr.substr(0, foundPos);
    _backStr = _targetStr.substr(foundPos + _delimiter.length());
    if (_backStr.length() > 0) _successFlag = true;
}

bool StringSpliter::getSuccessFlag(void) const {
    return _successFlag;
}

std::string StringSpliter::getFrontStr(void) const {
    if (!_successFlag) return NULL;

    return _frontStr;
}

std::string StringSpliter::getBackStr(void) const {
    if (!_successFlag) return NULL;

    return _backStr;
}
