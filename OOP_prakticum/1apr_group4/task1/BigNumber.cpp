#include "BigNumber.hpp"

void BigNumber::copy(const BigNumber &other)
{
    delete[] num;
    negative = other.negative;
    num = new (std::nothrow) char[strlen(other.num) + 1];
    assert(num);
    strcpy(num, other.num);
}

BigNumber::BigNumber(const BigNumber &other)
    : num(nullptr)
{
    copy(other);
}

BigNumber &BigNumber::operator+=(const BigNumber &other)
{
    *this = *this + other;
    return *this;
}

bool BigNumber::operator==(const BigNumber &other) const
{
    return (negative == other.negative &&
            !strcmp(num, other.num));
}

bool BigNumber::operator!=(const BigNumber &other) const
{
    return !(*this == other);
}

BigNumber BigNumber::operator+(const BigNumber &other) const
{
    if (negative && !other.negative)
        return other - (-*this);
    if (!negative && other.negative)
        return *this - (-other);
    if (negative && other.negative)
        return -(-*this + -other);
    BigNumber res;
    delete[] res.num;
    size_t resL = sumLength(other);
    res.num = new (std::nothrow) char[resL + 1];
    res.num[resL] = '\0';
    char *i = res.num + resL - 1;
    char *thisDigit = num + strlen(num) - 1;
    char *otherDigit = other.num + strlen(other.num) - 1;
    bool carry = false;
    while (thisDigit >= num && otherDigit >= other.num)
    {
        *i = carry + *thisDigit + *otherDigit - '0';
        if (*i > '9')
        {
            carry = true;
            *i -= 10;
        }
        else
            carry = false;
        --i;
        --thisDigit;
        --otherDigit;
    }
    while (thisDigit >= num)
    {
        *i = *thisDigit + carry;
        if (*i > '9')
        {
            carry = true;
            *i -= 10;
        }
        else
            carry = false;
        --i;
        --thisDigit;
    }
    while (otherDigit >= other.num)
    {
        *i = *otherDigit + carry;
        if (*i > '9')
        {
            carry = true;
            *i -= 10;
        }
        else
            carry = false;
        --i;
        --otherDigit;
    }
    if (carry)
        *i = '1';
    return res;
}

BigNumber &BigNumber::operator-=(const BigNumber &other)
{
    *this = *this - other;
    return *this;
}

BigNumber BigNumber::operator-(const BigNumber &other) const
{
    if (other.negative)
        return *this + -other;
    if (negative)
        return -(-*this + other);
    if (other > *this)
        return -(other - *this);
    BigNumber res(*this);

    bool carry(false);

    char *resDigit = res.num + strlen(res.num) - 1;
    char *otherDigit = other.num + strlen(other.num) - 1;
    while (otherDigit >= other.num)
    {
        *resDigit = *resDigit - carry - (*otherDigit - '0');
        if (*resDigit < '0')
        {
            *resDigit += 10;
            carry = true;
        }
        else
            carry = false;
        --resDigit;
        --otherDigit;
    }
    while (resDigit >= res.num)
    {
        *resDigit = *resDigit - carry;
        if (*resDigit < '0')
        {
            *resDigit += 10;
            carry = true;
        }
        else
            carry = false;
        --resDigit;
    }
    ++resDigit;
    while (*resDigit == '0')
        ++resDigit;
    if (!*resDigit)
        --resDigit;
    const char *end = resDigit;
    while (*end)
        ++end;
    char *newNum = new (std::nothrow) char[end - resDigit + 1];
    assert(newNum);
    strcpy(newNum, resDigit);
    delete[] res.num;
    res.num = newNum;
    return res;
}

BigNumber &BigNumber::operator*=(const BigNumber &other)
{
    *this = *this * other;
    return *this;
}

BigNumber BigNumber::operator*(const BigNumber &other) const
{
    char *otherDigit = other.num + strlen(other.num) - 1;
    BigNumber res = 0LL;
    BigNumber thisCpy = *this;
    thisCpy.negative = false;
    for (unsigned power = 0; otherDigit >= other.num; --otherDigit, ++power)
        res += thisCpy.simpleMultiply(*otherDigit - '0').mulPower10(power);
    res.negative = !(negative == other.negative);
    return res;
}

BigNumber &BigNumber::operator/=(const BigNumber &other)
{
    *this = *this / other;
    return *this;
}

BigNumber BigNumber::operator/(const BigNumber &other) const
{
    return BigNumber();
}

BigNumber &BigNumber::operator%=(const BigNumber &other)
{
    *this = *this % other;
    return *this;
}

BigNumber BigNumber::operator%(const BigNumber &other) const
{
    return BigNumber();
}

BigNumber::BigNumber(const char *number)
    : negative(*number == '-'),
      num(new (std::nothrow) char[strlen(number) + !negative])
{
    assert(isNumber(number) && num);
    if (negative)
        ++number;
    strcpy(num, number);
}

bool BigNumber::isNumber(const char *str) const
{
    if (*str == '-')
        ++str;
    while (*str && *str >= '0' && *str <= '9')
        ++str;
    return !*str;
}

std::ostream &operator<<(std::ostream &os, const BigNumber &N)
{
    if (N.negative)
        os << '-';
    return os << N.num;
}

std::istream &operator>>(std::istream &is, BigNumber &N)
{
    delete[] N.num;
    char buf[INPUT_MAX];
    is.getline(buf, INPUT_MAX);
    assert(N.isNumber(buf));
    N.negative = *buf == '-';
    N.num = new (std::nothrow) char[strlen(buf) + !N.negative];
    assert(N.num);
    strcpy(N.num, (N.negative ? buf + 1 : buf));
    return is;
}

bool BigNumber::operator>(const BigNumber &other) const
{
    if (!negative && other.negative)
        return true;
    if (negative && !other.negative)
        return false;
    if (negative && other.negative)
        return -other > (-*this);
    if (strlen(num) > strlen(other.num))
        return true;
    if (strlen(num) < strlen(other.num))
        return false;
    const char *thisDigit = num, *otherDigit = other.num;
    while (*thisDigit && *thisDigit == *otherDigit)
    {
        ++thisDigit;
        ++otherDigit;
    }
    return *thisDigit > *otherDigit;
}

BigNumber BigNumber::operator-() const
{
    BigNumber res(*this);
    res.negative = !res.negative;
    return res;
}

bool BigNumber::operator<(const BigNumber &other) const
{
    return other > *this;
}

BigNumber &BigNumber::operator=(const BigNumber &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

bool BigNumber::operator>=(const BigNumber &other) const
{
    return *this == other || *this > other;
}

bool BigNumber::operator<=(const BigNumber &other) const
{
    return *this == other || *this < other;
}

size_t BigNumber::sumLength(const BigNumber &other) const
{
    bool carry = false;
    unsigned thisL = strlen(num), otherL = strlen(other.num);
    const char *thisDigit = num + thisL - 1,
               *otherDigit = other.num + otherL - 1;
    while (thisDigit >= num && otherDigit >= other.num)
    {
        carry = (carry + *thisDigit + *otherDigit - '0' > '9');
        --thisDigit;
        --otherDigit;
    }
    while (thisDigit >= num)
    {
        carry = (carry + *thisDigit > '9');
        --thisDigit;
    }
    while (otherDigit >= other.num)
    {
        carry = (carry + *otherDigit > '9');
        --otherDigit;
    }
    return (thisL > otherL ? thisL + carry : otherL + carry);
}

BigNumber::BigNumber(long long int number)
{
    size_t size = 0;
    negative = (number < 0 ? (number = -number, true) : false);
    for (long long int n = number; n; n /= 10)
        ++size;
    if (!size)
        ++size;
    num = new (std::nothrow) char[size + 1];
    num[size] = '\0';
    assert(num);
    size_t i = size - 1;
    while (i < size)
    {
        num[i] = number % 10 + '0';
        number /= 10;
        --i;
    }
}

BigNumber BigNumber::simpleMultiply(unsigned n) const
{
    BigNumber res = 0LL;
    if (n == '9')
        std::cout << "here\n";
    for (unsigned i = 0; i < n; ++i)
        res += *this;
    return res;
}

BigNumber BigNumber::mulPower10(unsigned power) const
{
    if (!power)
        return *this;
    char *newNum = new (std::nothrow) char[strlen(num) + power + 1];
    strcpy(newNum, num);
    char *append0 = newNum + strlen(newNum);
    for (unsigned i = 0; i < power; ++i)
        append0[i] = '0';
    append0[power] = '\0';
    return newNum;
}
