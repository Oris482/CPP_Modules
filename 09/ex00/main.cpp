#include <iostream>
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"
#include "PriceDatabase.hpp"
#include "BitcoinExchange.hpp"

#define DATABASE_FILE "data.csv"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Only 1 argument" << std::endl;
        exit(1);
    }
    PriceDatabase priceDatabase;
    BitcoinExchange bitcoinExchange;

    if (!bitcoinExchange.setInputFile(argv[1])) {
        std::cout << "Can't open file: " << argv[1] << std::endl;
        exit(1);
    }
    
    if (!priceDatabase.inputFile(DATABASE_FILE)) {
        std::cout << "Can't open file: " << DATABASE_FILE << std::endl;
        exit(1);
    }
    bitcoinExchange.startExchange(priceDatabase);

    return 0;
}
