#include <iostream>
#include "Playlist.hpp"

int main()
{
    Playlist p;
    Song a;
    a.read();
    p.addSong(a);
    a.read();
    p.addSong(a);
    a.read();
    p.addSong(a);
    a.read();
    p.addSong(a);
    p.addSong(a);
    p.printPlaylistInfo();
    p.removeSong(a.getName());
    p.removeSong("abc");
    p.printPlaylistInfo();
    return 0;
}