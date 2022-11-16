// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Wed Nov 16 18:11:01 2022                      //
//                Last update : Wed Nov 16 18:11:01 2022                      //
//                Made by : jaesjeon <jaesjeon@student.42seoul.kr>            //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account:: _totalNbWithdrawals;

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    this->_amount = initial_deposit;
    _totalAmount += this->checkAmount();
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() \
        << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() \
        << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void  Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() \
        << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() \
        << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    if (INT_MAX - this->checkAmount() < deposit) {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() \
        << ";deposits:refused" << std::endl;
        return ;
    }
    const int pAmount = this->checkAmount();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << pAmount << ";deposit:" \
        << deposit << ";amount:" << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits \
        << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (this->checkAmount() < withdrawal) {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() \
        << ";withdrawal:refused" << std::endl;
        return false;
    }
    const int pAmount = this->checkAmount();
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << pAmount << ";withdrawal:" \
        << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals \
        << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() \
        << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals \
        << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t rawtime;
    struct tm * timeinfo;
    char    timestamp[19];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (timestamp, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << timestamp;
}
