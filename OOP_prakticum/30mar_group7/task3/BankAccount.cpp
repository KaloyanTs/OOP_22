#include "BankAccount.hpp"

BankAccount::BankAccount(const char *_name, const char *_account, double _money) : money(_money)
{
    strcpy(name, _name);
    strcpy(accountNumber, _account);
    std::clog << "BankAccount created.\n";
}

BankAccount::BankAccount() : money(0)
{
    *name = '\0';
    *accountNumber = '\0';
    std::clog << "BankAccount created.\n";
}

BankAccount &BankAccount::deposit(double sum)
{
    assert(sum >= 0);
    money += sum;
    return *this;
}
BankAccount &BankAccount::draw(double sum)
{
    assert(sum >= 0);
    money -= sum;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const BankAccount &bA)
{
    return os << bA.accountNumber
              << "\tOwner: " << bA.name
              << " has " << bA.money << '\n';
}

BankAccount::BankAccount(const BankAccount &other)
    : money(other.money)
{
    strcpy(name, other.name);
    strcpy(accountNumber, other.accountNumber);
    std::clog << "BankAccount created.\n";
}

BankAccount::~BankAccount()
{
    std::clog << "BankAccount deleted.\n";
}
