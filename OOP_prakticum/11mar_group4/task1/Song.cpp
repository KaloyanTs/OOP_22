#include "Song.hpp"
const size_t INPUT_MAX = 32;
const size_t SECONDS_MAX = 59;

Song::Song()
{
    name = genre = nullptr;
    duration = {0, 0};
    std::cout << "<Song created successfully.>\n";
}

Song::Song(const char *_name, unsigned timeSeconds, const char *_genre)
{
    char *newName = new (std::nothrow) char[strlen(_name) + 1];
    if (!newName)
    {
        std::cout << "<Failed to create a Song.>\n";
        return;
    }

    char *newGenre = new (std::nothrow) char[strlen(_genre) + 1];
    if (!newGenre)
    {
        std::cout << "<Failed to create a Song.>\n";
        delete[] newName;
        return;
    }
    strcpy(newName, _name);
    strcpy(newGenre, _genre);
    name = newName;
    genre = newGenre;
    duration.minutes = timeSeconds / 60;
    duration.seconds = timeSeconds % 60;
    std::cout << "<Song created successfully.>\n";
}

void Song::copy(const Song &S)
{
    char *newName = new (std::nothrow) char[strlen(S.name) + 1];
    if (!newName)
    {
        std::cout << "<Failed to copy a Song.>\n";
        return;
    }

    char *newGenre = new (std::nothrow) char[strlen(S.genre) + 1];
    if (!newGenre)
    {
        std::cout << "<Failed to copy a Song.>\n";
        delete[] newName;
        return;
    }
    strcpy(newName, S.name);
    strcpy(newGenre, S.genre);
    dealloc();
    name = newName;
    genre = newGenre;
    duration = S.duration;
    std::cout << "<Song copied successfully.>\n";
}

void Song::dealloc()
{
    if (name)
        delete[] name;
    if (genre)
        delete[] genre;
}

Song::Song(const Song &S)
{
    name = genre = nullptr;
    duration = {0, 0};
    copy(S);
    std::cout << "<Song created successfully.>\n";
}

void Song::setName(const char *_name)
{
    char *newName = new (std::nothrow) char[strlen(_name) + 1];
    if (!newName)
    {
        std::cout << "<Failed to set name of a Song.>\n";
        return;
    }
    strcpy(newName, _name);
    if (name)
        delete[] name;
    name = newName;
    std::cout << "<Name of a Song set successfully.>\n";
}

void Song::setGenre(const char *_genre)
{
    char *newGenre = new (std::nothrow) char[strlen(_genre) + 1];
    if (!newGenre)
    {
        std::cout << "<Failed to set genre of a Song.>\n";
        return;
    }
    strcpy(newGenre, _genre);
    if (genre)
        delete[] genre;
    genre = newGenre;
    std::cout << "<Genre of a Song set successfully.>\n";
}

void Song::setDurationMinutes(short min)
{
    duration.minutes = min;
    std::cout << "<Duration of a song modified successfully.>\n";
}

void Song::setDurationSeconds(short sec)
{
    duration.seconds = sec;
    std::cout << "<Duration of a song modified successfully.>\n";
}

const Song &Song::operator=(const Song &S)
{
    if (this != &S)
        copy(S);
    return *this;
}

void Song::print() const
{
    std::cout << "Name: " << name << "\tDuration: ";
    duration.print();
    std::cout << "\tGenre: " << genre << '\n';
}

Song::~Song()
{
    dealloc();
    std::cout << "<Song deleted successfully.>\n";
}

void Song::read()
{
    char _name[INPUT_MAX], _genre[INPUT_MAX];
    short mins, secs;
    char sign;
    std::cout << "Enter name of song: ";
    std::cin.getline(_name, INPUT_MAX);
    std::cout << "Enter duration of song: ";
    std::cin >> mins >> sign >> secs;
    assert(sign == ':' && secs <= SECONDS_MAX);
    std::cin.ignore();
    std::cout << "Enter genre of song: ";
    std::cin.getline(_genre, INPUT_MAX);

    char *newName = new (std::nothrow) char[strlen(_name) + 1];
    if (!newName)
    {
        std::cout << "<Failed to read a Song.>\n";
        return;
    }

    char *newGenre = new (std::nothrow) char[strlen(_genre) + 1];
    if (!newGenre)
    {
        std::cout << "<Failed to read a Song.>\n";
        delete[] newName;
        return;
    }
    strcpy(newName, _name);
    strcpy(newGenre, _genre);
    this->dealloc();
    name = newName;
    genre = newGenre;
    duration.minutes = mins;
    duration.seconds = secs;
    std::cout << "<Song read successfully.>\n";
}
