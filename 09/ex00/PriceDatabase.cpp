#include "PriceDatabase.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"

float PriceDatabase::getValue(const std::string date) const {
    std::string valueStr;
    float value;
    char *pEnd;

    std::map<std::string, std::string>::const_iterator exactPrice = _database.find(date);
    if (exactPrice != _database.end()) {
        valueStr = exactPrice->second;
    } else {
        std::map<std::string, std::string>::const_iterator earlyPrice = _database.lower_bound(date);
        if (earlyPrice != _database.end()) {
            valueStr = earlyPrice->second;
        } else return NOT_FOUND;
    }

    value = strtof(valueStr.c_str(), &pEnd);
    if (errno == ERANGE || *pEnd != '\0' || value < 0) {
        errno = 0;
        std::cout << "Wrong Value: " << valueStr << std::endl;
        return NOT_FOUND;
    }
    return value;
}

bool PriceDatabase::inputFile(const std::string file) {
    std::ifstream ifs;
    char line[101];

    memset(line, 0, 101);
    try {
        ifs.open(file, std::ifstream::in);
        while (ifs.getline(line, 100) && ifs.good()) {
            StringSpliter spliter(line, PRICE_DELIMITER);

            if (!spliter.getSuccessFlag()) {
                std::cout << "Wrong format: " << line << std::endl;
                continue ;
            }
            if (strcmp(spliter.getFrontStr().c_str(), "date") == 0
                && strcmp(spliter.getBackStr().c_str(), "exchange_rate") == 0)
                continue ;

            if (!insert(spliter.getFrontStr(), spliter.getBackStr()))
                std::cout << "Duplicate price: " << line << std::endl;
        }
    } catch (std::exception &e) {
        e.what();
        return false;
    }
    return true;
}
