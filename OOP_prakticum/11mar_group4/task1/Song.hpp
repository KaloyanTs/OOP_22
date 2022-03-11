#ifndef __SONG_HPP
#define __SONG_HPP
#include "Duration.hpp"
#include <iostream>
#include <cstring>
#include <cassert>

class Song
{
    char *name;
    Duration duration;
    char *genre;
    void copy(const Song &S);
    void dealloc();

public:
    Song();
    Song(const char *_name, unsigned timeSeconds, const char *_genre);
    Song(const Song &S);
    void read();
    const char *getName() const { return name; }
    void setName(const char *_name);
    const char *getGenre() const { return genre; }
    void setGenre(const char *_genre);
    short getDurationMinutes() const { return duration.minutes; }
    void setDurationMinutes(short min);
    short getDurationSeconds() const { return duration.seconds; }
    void setDurationSeconds(short sec);
    const Song &operator=(const Song &S);
    void print() const;
    ~Song();
};

#endif