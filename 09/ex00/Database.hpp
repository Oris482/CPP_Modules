#pragma once

#ifndef DATABASE_H__
# define DATABASE_H__

# include <string>
# include <map>
# include <iostream>
# include <fstream>

class Database {
    protected:
        size_t _dataSize;
        std::map<std::string, std::string> _database;

    public:
        Database(void);
        ~Database();
        Database(const Database& src);
        Database& operator= (const Database& src);

        bool insert(const std::string date, const std::string value);
        size_t getDataSize(void) const;
        void printAllData(void) const;
        virtual double getValue(const std::string date) const = 0;
        virtual bool inputFile(const std::string file) = 0;
};

#endif
