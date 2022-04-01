#include "Bank.hpp"

void Bank::clean()
{
    for (unsigned i = 0; i < count; ++i)
        delete accounts[i];
    delete[] accounts;
}

Bank::Bank(const Bank &other)
    : accounts(nullptr)
{
    copy(other);
    std::clog << "Bank created.\n";
}

Bank::~Bank()
{
    clean();
    std::clog << "Bank deleted.\n";
}

Bank &Bank::addAccount(const BankAccount &bA)
{
    if (count == capacity)
        resize(2 * capacity);
    accounts[count] = new (std::nothrow) BankAccount(bA);
    assert(accounts[count++]);
    std::clog << "BankAccount added to Bank.\n";
    return *this;
}

Bank &Bank::removeAccount(const char *account)
{
    unsigned i = 0;
    while (i < count && strcmp(account, accounts[i]->accountNumber))
        ++i;
    if (i == count)
        return *this;
    delete accounts[i];
    while (i < count - 1)
    {
        accounts[i] = accounts[i + 1];
        ++i;
    }
    --count;
    std::clog << "BankAccount removed from Bank.\n";
    return *this;
}

double Bank::getAccountBalance(const char *account) const
{
    unsigned i = 0;
    while (i < count && strcmp(account, accounts[i]->accountNumber))
        ++i;
    return (i < count ? accounts[i]->money : 0);
}

double Bank::getClientBalance(const char *name) const
{
    double res = 0;
    for (unsigned i = 0; i < count; ++i)
        if (!strcmp(name, accounts[i]->name))
            res += accounts[i]->money;
    return res;
}

Bank::Bank()
    : count(0), capacity(INIT_CAPACITY)
{
    accounts = new (std::nothrow) BankAccount *[capacity];
    assert(accounts);
    std::clog << "Bank created.\n";
}

void Bank::resize(size_t newSize)
{
    assert(newSize > capacity);
    capacity = newSize;
    BankAccount **newArr = new (std::nothrow) BankAccount *[capacity];
    assert(newArr);
    for (unsigned i = 0; i < count; ++i)
        newArr[i] = accounts[i];
    delete[] accounts;
    accounts = newArr;
}

void Bank::copy(const Bank &other)
{
    clean();
    count = other.count;
    capacity = other.capacity;
    accounts = new (std::nothrow) BankAccount *[capacity];
    assert(accounts);
    for (unsigned i = 0; i < count; ++i)
    {
        accounts[i] = new (std::nothrow) BankAccount(*other.accounts[i]);
        assert(accounts[i]);
    }
}

Bank::Bank(BankAccount *arr, size_t size)
{
    count = capacity = size;
    accounts = new (std::nothrow) BankAccount *[capacity];
    assert(accounts);
    for (unsigned i = 0; i < count; ++i)
    {
        accounts[i] = new (std::nothrow) BankAccount(arr[i]);
        assert(accounts[i]);
    }
    std::clog << "Bank created.\n";
}

std::ostream &operator<<(std::ostream &os, const Bank &B)
{
    os << "Accounts: " << B.count << '\n';
    for (unsigned i = 0; i < B.count; ++i)
        os << *B.accounts[i];
    return os;
}