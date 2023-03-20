#include "Database.hpp"
#include "StringSpliter.hpp"
#include "FormatValidator.hpp"

Database::Database(void): _dataSize(0) {}

Database::~Database() {}

Database::Database(const Database& src) {
    *this = src;
}

Database& Database::operator= (const Database& src) {
    if (this != &src) {
        _dataSize = src._dataSize;
        _database = src._database;
    }

    return *this;
}

bool Database::insert(const std::string date, const std::string value) {
    if (_database.find(date) != _database.end()) return false;

    try {
        _database.insert(make_pair(date, value));
    } catch (std::exception& e) {
        e.what();
        exit(1);
    }
    ++_dataSize;
    return true;
}

void Database::printAllData(void) const {
    for (std::map<std::string, std::string>::const_iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << "," << it->second << "\n";
    }
}

size_t Database::getDataSize(void) const {
    return _dataSize;
}
