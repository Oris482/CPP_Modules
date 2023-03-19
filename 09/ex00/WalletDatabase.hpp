#pragma once

#ifndef WALLETDATABASE_H__
# define WALLETDATABASE_H__

# define WRONG_VALUE -1

# include <string>
# include <map>
# include "Database.hpp"

class WalletDatabase: public Database {
    private:

    public:
        float getValue(const std::string date) const;
        bool inputFile(const std::string file);
};

#endif
