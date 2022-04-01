#include <iostream>
#include "Bank.hpp"

int main()
{
    BankAccount accountOfIvan("Ivan", "1", 2000);
    BankAccount accountOfPetar("Petar", "2", 500);
    BankAccount secondAccountOfIvan("Ivan", "3", 400);

    BankAccount accounts[] = {accountOfIvan, accountOfPetar};
    Bank bank(accounts, 2);
    bank.addAccount(secondAccountOfIvan); // добавя втора сметка на "Ivan" в банката

    std::cout << bank.getAccountBalance("2") << '\n'; // 500
    bank.removeAccount("2");                          // премахва сметката на "Petar" от банката

    std::cout << bank.getClientBalance("Ivan") << '\n'; // 2400
    std::cout << bank;
    return 0;
}