OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

all: 2048.exe alg1.exe alg2.exe alg3.exe
	rm *.o

2048.exe: 2048.o Grid.o
	g++ -o 2048.exe 2048.o Grid.o

alg1.exe: alg1.o Grid.o
	g++ -o alg1.exe alg1.o Grid.o

alg2.exe: alg2.o Grid.o
	g++ -o alg2.exe alg2.o Grid.o

alg3.exe: alg3.o Grid.o
	g++ -o alg3.exe alg3.o Grid.o

2048.o: 2048.cc Grid.hh
	g++ -c 2048.cc $(OPTIONS)

alg1.o: alg1.cc Grid.hh
	g++ -c alg1.cc $(OPTIONS)

alg2.o: alg2.cc Grid.hh
	g++ -c alg2.cc $(OPTIONS)

alg3.o: alg3.cc Grid.hh
	g++ -c alg3.cc $(OPTIONS)

Grid.o: Grid.cc Grid.hh
	g++ -c Grid.cc $(OPTIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
