OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

all: 2048.exe
	rm *.o

2048.exe: 2048.o Grid.o AImSorryDave.o AImStupid.o
	g++ -o 2048.exe 2048.o Grid.o AImSorryDave.o AImStupid.o $(OPTIONS)

2048.o: 2048.cc Grid.hh AImSorryDave.hh Human.hh AImStupid.hh Player.hh
	g++ -c 2048.cc $(OPTIONS)

AImStupid.o: AImStupid.cc AImStupid.hh Player.hh
	g++ -c AImStupid.cc $(OPTIONS)

AImSorryDave.o: AImSorryDave.cc AImSorryDave.hh Player.hh
	g++ -c AImSorryDave.cc $(OPTIONS)

Grid.o: Grid.cc Grid.hh
	g++ -c Grid.cc $(OPTIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
