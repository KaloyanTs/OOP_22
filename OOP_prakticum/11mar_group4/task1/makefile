main: main.o Duration.o Song.o Playlist.o
	g++ -o music.exe main.o Duration.o Song.o Playlist.o
main.o: main.cpp Playlist.o
	g++ -g -c main.cpp
Duration.o: Duration.hpp Duration.cpp
	g++ -g -c Duration.cpp
Song.o: Song.cpp Song.hpp Duration.o
	g++ -g -c Song.cpp 
Playlist.o: Playlist.hpp Playlist.cpp Song.o
	g++ -g -c Playlist.cpp
clean:
	del *.o *.exe