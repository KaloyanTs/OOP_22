#ifndef __BANKACCOUNT_HPP
#define __BANKACCOUNT_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const size_t NAME_MAX = 32;
const size_t ACCOUNT_MAX = 16;

class BankAccount
{
    char name[NAME_MAX];
    char accountNumber[ACCOUNT_MAX];
    double money;

public:
    BankAccount();
    BankAccount(const char *_name, const char *_account, double _money = 0);
    BankAccount(const BankAccount &other);
    BankAccount &deposit(double sum);
    BankAccount &draw(double sum);
    friend std::ostream &operator<<(std::ostream &os, const BankAccount &bA);
    friend class Bank;
    ~BankAccount();
};

#endif