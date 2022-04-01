#ifndef __BANK_HPP
#define __BANK_HPP
#include "BankAccount.hpp"
const size_t INIT_CAPACITY = 1;

class Bank
{
    size_t count, capacity;
    BankAccount **accounts;
    void copy(const Bank &other);
    void clean();
    void resize(size_t newSize);

public:
    Bank();
    Bank(BankAccount *arr, size_t size);
    Bank(const Bank &other);
    ~Bank();
    Bank &addAccount(const BankAccount &bA);
    Bank &removeAccount(const char *account);
    double getAccountBalance(const char *account) const;
    double getClientBalance(const char *name) const;
    friend std::ostream &operator<<(std::ostream &os, const Bank &B);
};

#endif