#include <iostream>
#include <cassert>
#include <cstring>

struct Record
{
    char *oldW = nullptr;
    char *newW = nullptr;
    bool init()
    {
        size_t L;
        std::cout << "Enter length of first word: ";
        std::cin >> L;
        oldW = new (std::nothrow) char[L + 1];
        if (!oldW)
            return false;
        std::cin.ignore();
        std::cout << "Enter the first word: ";
        std::cin.getline(oldW, L + 1);
        std::cout << "Enter length of second word: ";
        std::cin >> L;
        newW = new (std::nothrow) char[L + 1];
        if (!newW)
        {
            delete oldW;
            return false;
        }
        std::cin.ignore();
        std::cout << "Enter the second word: ";
        std::cin.getline(newW, L + 1);
        return true;
    }
    void print()
    {
        if (oldW)
            std::cout << oldW << " - " << newW << '\n';
    }
    void dealloc()
    {
        delete[] oldW;
        delete[] newW;
    }
};

struct Dictionary
{
    Record *records = nullptr;
    size_t length;
    bool init()
    {
        std::cout << "Enter count of records in the dictionary: ";
        std::cin >> length;
        records = new (std::nothrow) Record[length];
        if (!records)
            return false;
        unsigned i = 0;
        while (i < length && records[i].init())
            ++i;
        if (i < length)
            for (unsigned j = 0; j < i; ++j)
                records[j].dealloc();
        return i == length;
    }
    void print()
    {
        std::cout << "---------------\n";
        if (records)
            for (unsigned i = 0; i < length; ++i)
                records[i].print();
        std::cout << "---------------\n";
    }
    void dealloc()
    {
        if (records)
        {
            for (unsigned i = 0; i < length; ++i)
                records[i].dealloc();
            delete[] records;
        }
    }
};

void appendWord(const char *word, char *&output)
{
    while (*word)
        *output++ = *word++;
}

struct Sentence
{
    size_t length = 0;
    char *content = nullptr;
    bool init()
    {
        std::cout << "Enter length of the sentence: ";
        std::cin >> length;
        if (content)
            delete[] content;
        content = new (std::nothrow) char[length + 1];
        if (!content)
            return false;
        std::cin.ignore();
        std::cout << "Enter the sentence:\n";
        std::cin.getline(content, length + 1);
        return true;
    }
    void print()
    {
        if (content)
            std::cout << content << '\n';
    }
    unsigned searchRecord(const char *begin, const Record &rec)
    {
        const char *res = strstr(begin, rec.oldW);
        if (res != begin)
            return 0;
        return strlen(rec.oldW);
    }
    unsigned searchDict(const char *&begin, const Dictionary &dict)
    {
        unsigned res = 0;
        unsigned i = 0;
        while (i < dict.length && !res)
        {
            res = searchRecord(begin, dict.records[i]);
            if (!res)
                ++i;
        }
        begin += res;
        return i;
    }
    size_t maxSize(size_t length)
    {
        return (2 * length + 1 > 64 ? 2 * length + 1 : 64);
    }
    bool replace(const Dictionary &dict)
    {
        char *const newS = new (std::nothrow) char[maxSize(length)];
        if (!newS)
            return false;
        char *newSEnd = newS;
        const char *iter = content;
        unsigned res = 0;
        while (*iter)
        {
            res = searchDict(iter, dict);
            if (res < dict.length)
                appendWord(dict.records[res].newW, newSEnd);
            else
                *newSEnd++ = *iter++;
        }
        *newSEnd = '\0';
        delete[] content;
        content = new (std::nothrow) char[newSEnd - newS + 1];
        if (!content)
        {
            delete[] newS;
            return false;
        }
        strcpy(content, newS);
        length = newSEnd - newS;
        delete[] newS;
        return true;
    }
    void dealloc()
    {
        if (content)
            delete[] content;
    }
};

int main()
{
    Dictionary dict;
    if (!dict.init())
    {
        std::cout << "Not enough memory for the dictionary!\n";
        return 0;
    }
    size_t sentenceL;
    Sentence s;
    if (!s.init() || !s.replace(dict))
    {
        std::cout << "Not enough memory for the sentence!\n";
        dict.dealloc();
        s.dealloc();
        return 0;
    }
    s.print();
    s.dealloc();
    dict.dealloc();
    return 0;
}