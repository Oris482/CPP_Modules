#pragma once

#include "PriceDatabase.hpp"
#ifndef BITCOINEXCHANGE_H__
# define BITCOINEXCHANGE_H__

# include <string>
# include <iostream>
# include <fstream>

class PriceDatabase;

class BitcoinExchange {
    private:
        std::ifstream _ifs;

        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator= (const BitcoinExchange& src);

    public:
        BitcoinExchange(void);
        ~BitcoinExchange();

        bool setInputFile(const std::string file);
        void startExchange(const PriceDatabase& priceDatabase);
};

#endif
