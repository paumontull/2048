OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

2048.exe: 2048.o Grid.o Tile.o
	g++ -o 2048.exe 2048.o  Grid.o Tile.o
	rm *.o

2048.o: 2048.cc Grid.hh
	g++ -c 2048.cc $(OPTIONS)

Grid.o: Grid.cc Grid.hh Tile.hh
	g++ -c Grid.cc $(OPTIONS)

Tile.o: Tile.cc Tile.hh
	g++ -c Tile.cc $(OPTIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
