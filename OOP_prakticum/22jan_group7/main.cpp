#include <iostream>
#include <cstring>
const unsigned NAME_MAX = 32;

enum SwordType
{
    SHARP,
    HEAVY_DAMAGE,
    COMPACT
};

void inputSwordType(SwordType &sT)
{
    unsigned buf;
    std::cin >> buf;
    if (buf == 1)
        sT = SHARP;
    else if (buf == 2)
        sT = HEAVY_DAMAGE;
    else if (buf == 3)
        sT = COMPACT;
    else
        std::cout << "Invalid input!\n";
}

void printSwordType(const SwordType &sT)
{
    if (sT == SHARP)
        std::cout << "SHARP";
    else if (sT == HEAVY_DAMAGE)
        std::cout << "HEAVY_DAMAGE";
    else if (sT == COMPACT)
        std::cout << "COMPACT";
    else
        std::cout << "Not initialized!";
}

struct Sword
{
    char model[NAME_MAX];
    unsigned power;
    SwordType type;
    unsigned forgeYear;
};

struct Warrior
{
    char name[NAME_MAX];
    unsigned age;
    Sword s;
};

void initializeSword(Warrior &warrior)
{
    std::cout << "Enter sword model: ";
    std::cin.getline(warrior.s.model, NAME_MAX);
    std::cout << "Enter sword power: ";
    std::cin >> warrior.s.power;
    std::cout << "Enter sword type: ";
    inputSwordType(warrior.s.type);
    std::cout << "Enter year of forging of the sword: ";
    std::cin >> warrior.s.forgeYear;
    std::cin.ignore();
}

void initializeWarrior(Warrior &warrior)
{
    std::cout << "Enter warrior's name: ";
    std::cin.getline(warrior.name, NAME_MAX);
    std::cout << "Enter warrior's age: ";
    std::cin >> warrior.age;
    std::cout << "Initialize the sword:\n";
    std::cin.ignore();
    initializeSword(warrior);
}

void printWarrior(const Warrior &warrior)
{
    std::cout << "Name: " << warrior.name << '\n';
    std::cout << "Age: " << warrior.age << '\n';
    std::cout << "Sword:\n";
    std::cout << "\tModel: " << warrior.s.model << '\n';
    std::cout << "\tPower: " << warrior.s.power << '\n';
    std::cout << "\tType: ";
    printSwordType(warrior.s.type);
    std::cout << "\n\tForged in: " << warrior.s.forgeYear << '\n';
}

int main()
{
    Warrior *w = new Warrior;
    initializeWarrior(*w);
    printWarrior(*w);
    delete w;
    return 0;
}