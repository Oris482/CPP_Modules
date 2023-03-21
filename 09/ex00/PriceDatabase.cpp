#include "PriceDatabase.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"

double PriceDatabase::getValue(const std::string date) const {
    std::string valueStr;
    double value;
    char *pEnd;

    std::map<std::string, std::string>::const_iterator boundPrice = _database.lower_bound(date);
    // 해당 날짜에 데이터가 있는 경우
    if (boundPrice != _database.end() && date.compare(boundPrice->first) == 0) {
        valueStr = boundPrice->second;
    // 해당 날짜에 데이터가 없는 경우
    } else {
        // 제일 오래된 날짜 이전인 경우
        if (boundPrice == _database.begin()) return NOT_FOUND;

        // 과거 데이터가 있는 경우
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
            StringSpliter spliter(line, CSV_DELIMITER);

            // 구분자가 없는 경우
            if (!spliter.getSuccessFlag()) {
                std::cout << "Wrong format: " << line << std::endl;
                continue ;
            }
            // 항목 표시줄 패스
            if (spliter.getFrontStr().compare("date") == 0
                && spliter.getBackStr().compare("exchange_rate") == 0)
                continue ;

            if (!insert(spliter.getFrontStr(), spliter.getBackStr()))
                std::cout << "Duplicate price: " << line << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;;
        return false;
    }
    return true;
}
