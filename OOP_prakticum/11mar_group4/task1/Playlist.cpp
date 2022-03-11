#include "Playlist.hpp"

Playlist::Playlist()
{
    name = nullptr;
    songs = nullptr;
    songCount = 0;
    std::cout << "<Playlist created successfully.>\n";
}

Playlist::Playlist(const char *_name)
{
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name)
        std::cout << "<Playlist could not be created properly.>\n";
    else
        strcpy(name, _name);
    songs = nullptr;
    songCount = 0;
    if (name)
        std::cout << "<Playlist created successfully.>\n";
}

void Playlist::copy(const Playlist &P)
{
    char *pname = new (std::nothrow) char[strlen(P.name) + 1];
    if (!pname)
    {
        std::cout << "<Copying Playlist failed.>\n";
        return;
    }
    strcpy(pname, P.name);
    if (!P.songs)
    {
        if (songs)
            dealloc(songs, songCount);
        songs = nullptr;
        if (name)
            delete[] name;
        name = pname;
        std::cout << "<Playlist copied successfully.>\n";
    }
    Song **newList = new (std::nothrow) Song *[P.songCount];
    if (!newList)
    {
        std::cout << "<Copying a Playlist failed.>\n";
        delete[] pname;
        return;
    }

    unsigned i = 0;
    while (i < P.songCount)
    {
        newList[i] = new (std::nothrow) Song(*P.songs[i]);
        if (!newList[i])
        {
            std::cout << "<Copying a Playlist failed..>\n";
            dealloc(newList, i);
            delete[] pname;
            return;
        }
        ++i;
    }
    if (songs)
        dealloc(songs, songCount);
    songs = newList;
    songCount = P.songCount;
    if (name)
        delete[] name;
    name = pname;
    std::cout << "<Playlist copied successfully.>\n";
}

void Playlist::dealloc(Song **arr, size_t size)
{
    for (unsigned i = 0; i < size; ++i)
        delete arr[i];
    delete[] arr;
}

int Playlist::getSongIndex(const char *songName) const
{
    unsigned i = 0;
    while (i < songCount && strcmp(songName, songs[i]->getName()))
        ++i;
    return (i < songCount ? i : -1);
}

Playlist::Playlist(const Playlist &P)
{
    songs = nullptr;
    name = nullptr;
    copy(P);
}

const Playlist &Playlist::operator=(const Playlist &P)
{
    copy(P);
    return *this;
}

void Playlist::addSong(const Song &songToAdd)
{
    if (getSongIndex(songToAdd.getName()) >= 0)
        return;
    Song **newList = new (std::nothrow) Song *[songCount + 1];
    if (!newList)
    {
        std::cout << "<Adding a Song failed.>\n";
        return;
    }

    unsigned i = 0;
    while (i < songCount)
    {
        newList[i] = songs[i];
        ++i;
    }
    newList[songCount] = new (std::nothrow) Song(songToAdd);
    if (!newList[songCount])
    {
        delete[] newList;
        std::cout << "<Adding a Song failed.>\n";
        return;
    }
    ++songCount;
    delete[] songs;
    songs = newList;
    std::cout << "<Song added successfully.>\n";
}

bool Playlist::removeSong(const char *songName)
{
    int i = getSongIndex(songName);
    if (!songs || i < 0)
        return false;
    if (songCount == 1)
    {
        delete *songs;
        delete songs;
        return true;
    }

    Song **newList = new (std::nothrow) Song *[songCount - 1];
    if (!newList)
    {
        std::cout << "<Removing a Song failed.>\n";
        return false;
    }
    delete songs[i];
    unsigned j = 0;
    while (j < i)
    {
        newList[j] = songs[j];
        ++j;
    }
    while (j < songCount - 1)
    {
        newList[j] = songs[j + 1];
        ++j;
    }
    delete[] songs;
    --songCount;
    songs = newList;
    std::cout << "<Song removed successfully.>\n";
    return true;
}

void Playlist::printPlaylistInfo() const
{
    std::cout << "Playlist \"" << (name ? name : "") << "\"\n\t"
              << songCount << " song";
    if (songCount != 1)
        std::cout << 's';
    if (songCount)
        std::cout << ":\n";
    for (unsigned i = 0; i < songCount; ++i)
    {
        std::cout << '\t';
        songs[i]->print();
    }
}

Playlist::~Playlist()
{
    dealloc(songs, songCount);
    if (name)
        delete[] name;
    std::cout << "<Playlist deleted successfully.>\n";
}
