#include "BitcoinExchange.hpp"
#include "PriceDatabase.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {
    if (_ifs.is_open()) _ifs.close();
}

bool BitcoinExchange::setInputFile(const std::string file) {
    try {
        _ifs.open(file, std::ifstream::in);

        if (_ifs.fail()) return false;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;;
        return false;
    }

    return true;
}

void BitcoinExchange::startExchange(const PriceDatabase& priceDatabase) {
    if (priceDatabase.getDataSize() == 0) {
        std::cout << "Price database is empty." << std::endl;
        return ;
    }

    char line[51];

    memset(line, 0, 51);
    try {
        while (_ifs.getline(line, 50) && _ifs.good()) {
            StringSpliter spliter(line, INPUT_DELIMITER);

            if (!spliter.getSuccessFlag()) {
                std::cout << "Wrong format: " << line << std::endl;
                continue ;
            }
            if (spliter.getFrontStr().compare("date") == 0
                && spliter.getBackStr().compare("value") == 0)
                continue ;
            // Exchange Part
            const float amount = strtof(spliter.getBackStr().c_str(), NULL);

            if (!FormatValidator::isValidDate(spliter.getFrontStr())) {
                std::cout << "Wrong date: " << spliter.getFrontStr() << std::endl;
                continue ;
            } else if (!FormatValidator::isFloat(spliter.getBackStr()) 
                        || (amount < 0 || amount > 1000)) {
                std::cout << "Wrong value: " << spliter.getBackStr() << std::endl;
                continue ;
            }

            const double exchangeRate = priceDatabase.getValue(spliter.getFrontStr());
            if (exchangeRate == NOT_FOUND) {
                std::cout << "No data for this date: " << spliter.getFrontStr() << std::endl;
                continue ;
            }

            std::cout << spliter.getFrontStr() << " => " << spliter.getBackStr() << " = " << static_cast<float>(exchangeRate * amount) << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;;
        return ;
    }
}
