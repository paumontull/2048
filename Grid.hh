#include "Tile.hh"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Grid{

//Tipus de modul: dades
//Descripcio del tipus:

private:
	
	vector<Tile> cells;
	int _size;
	int _nCells;
	int _freeCells;
	int _maxValue;
	int _score;
	
	void addTiles(int n);
	
	void slide(int curr, int step, int min, int max);
	
	void merge(int curr, int step, int min, int max);
	
	void printTop();
	
	void printMid();
	
	void printBottom();
	
public:
	
	/* Constructores */
	
	//Grid();
	
	Grid(int size = 4);
	
	/* Destructora per defecte */
	
	~Grid();
	
	/* Modificadores */
	
	void push(char direction);
	//Pre: 'direction' is one of these characters: 'u'(up), 'd'(down), 'l'(left), 'r'(right)
	//Post: Every tile has been moved in the 'direction' direction until merging with an equivalent tile, stopping at a different value tile or reaching the edge
	
	/* Consultores */
	
	/* Entrada/Sortida */
	
	void print();
	
};
