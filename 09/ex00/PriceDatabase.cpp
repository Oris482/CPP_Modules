#include "PriceDatabase.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"
#include <cstdlib>

double PriceDatabase::getValue(const std::string date) const {
    std::string valueStr;
    double value;
    char *pEnd;

    std::map<std::string, std::string>::const_iterator boundPrice = _database.lower_bound(date);
    if (date.compare(boundPrice->first) == 0) {
        valueStr = boundPrice->second;
    } else {
        if (boundPrice == _database.begin()) return NOT_FOUND;

        --boundPrice;
        valueStr = boundPrice->second;
    }

    value = strtod(valueStr.c_str(), &pEnd);
    if (errno == ERANGE || *pEnd != '\0' || value < 0) {
        errno = 0;
        std::cout << "Wrong Value: " << valueStr << std::endl;
        return NOT_FOUND;
    }
    return value;
}

bool PriceDatabase::inputFile(const std::string file) {
    std::ifstream ifs;
    char line[51];

    memset(line, 0, 51);
    try {
        ifs.open(file, std::ifstream::in);

        if (ifs.fail()) return false;
        
        while (ifs.getline(line, 50) && ifs.good()) {
            StringSpliter spliter(line, PRICE_DELIMITER);

            if (!spliter.getSuccessFlag()) {
                std::cout << "Wrong format: " << line << std::endl;
                continue ;
            }
            if (spliter.getFrontStr().compare("date") == 0
                && spliter.getBackStr().compare("exchange_rate") == 0)
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
