#include "WalletDatabase.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"

float WalletDatabase::getValue(const std::string date) const {
    std::map<std::string, std::string>::const_iterator exactValue = _database.find(date);
    if (exactValue != _database.end()) {
        float value;
        char *pEnd;

        value = strtof(exactValue->second.c_str(), &pEnd);
        if (errno == ERANGE || *pEnd != '\0' || value < 0 || value > 1000) {
            errno = 0;
            std::cout << "Wrong Value: " << exactValue->second << std::endl;
            return WRONG_VALUE;
        }
        return value;
    }

    return WRONG_VALUE;
}

bool WalletDatabase::inputFile(const std::string file) {
    std::ifstream ifs;
    char line[101];

    memset(line, 0, 101);
    try {
        ifs.open(file, std::ifstream::in);
        while (ifs.getline(line, 100) && ifs.good()) {
            StringSpliter spliter(line, WALLET_DELIMITER);

            if (!spliter.getSuccessFlag()) {
                std::cout << "Wrong format: " << line << std::endl;
                continue ;
            }
            if (strcmp(spliter.getFrontStr().c_str(), "date") == 0
                && strcmp(spliter.getBackStr().c_str(), "value") == 0)
                continue ;

            if (!insert(spliter.getFrontStr(), spliter.getBackStr()))
                std::cout << "Duplicate amount: " << line << std::endl;
        }
    } catch (std::exception &e) {
        e.what();
        return false;
    }
    return true;
}
