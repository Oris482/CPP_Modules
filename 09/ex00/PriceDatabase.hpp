#pragma once

#ifndef PRICEDATABASE_H__
# define PRICEDATABASE_H__

# define NOT_FOUND -1

# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include "Database.hpp"

# define NOT_FOUND -1

class PriceDatabase: public Database {
    private:

    public:
        float getValue(const std::string date) const;
        bool inputFile(const std::string file);
};

#endif
