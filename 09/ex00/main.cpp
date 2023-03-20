#include <iostream>
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"
#include "PriceDatabase.hpp"
#include "BitcoinExchange.hpp"

#define DEFAULT_DATABASE_FILE "data.csv"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Least 1 argument" << std::endl;
        exit(1);
    }
    PriceDatabase priceDatabase;
    BitcoinExchange bitcoinExchange;

    if (!bitcoinExchange.setInputFile(argv[1])) {
        std::cout << "Can't open file: " << argv[1] << std::endl;
        exit(1);
    }
    
    if (argc == 2) {
        if (!priceDatabase.inputFile(DEFAULT_DATABASE_FILE))
            std::cout << "Can't open file: " << DEFAULT_DATABASE_FILE << std::endl;
    } else {
        for(int i = 2; i < argc; ++i) {
            if (!FormatValidator::isValidExtension(argv[i], ".csv")) {
                std::cout << "Not csv file: " << argv[i] << std::endl;
                continue ;
            }
            if (!priceDatabase.inputFile(argv[i]))
                std::cout << "Can't open file: " << argv[i] << std::endl;
        }
    }
    bitcoinExchange.startExchange(priceDatabase);

    return 0;
}
