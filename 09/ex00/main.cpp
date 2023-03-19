#include <iostream>
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"
#include "PriceDatabase.hpp"
#include "WalletDatabase.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Only 1 argument" << std::endl;
        exit(1);
    }
    PriceDatabase priceDatabase;
    WalletDatabase walletDatabase;

    walletDatabase.inputFile(argv[1]);
    walletDatabase.printAllData();
    // database.inputFile("./data.csv");
    // database.printAllData();

    return 0;
}
