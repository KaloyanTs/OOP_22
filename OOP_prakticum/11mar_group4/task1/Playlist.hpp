#ifndef __PLAYLIST_HPP
#define __PLAYLIST_HPP
#include "Song.hpp"

class Playlist
{
    char *name;
    Song **songs;
    size_t songCount;
    void copy(const Playlist &P);
    void dealloc(Song **arr, size_t size);
    int getSongIndex(const char *songName) const;

public:
    Playlist();
    Playlist(const char *name);
    Playlist(const Playlist &P);
    const Playlist &operator=(const Playlist &P);
    void addSong(const Song &songToAdd);
    bool removeSong(const char *songName);
    void printPlaylistInfo() const;
    ~Playlist();
};

#endif