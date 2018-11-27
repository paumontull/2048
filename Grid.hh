#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Grid{

//Tipus de modul: dades
//Descripcio del tipus:

private:

	vector<int> cells;
	int _size;
	int _nCells;
	int _freeCells;
	bool _moved;
	bool _gameOver;
	int _max;
	int _score;

	//Pre: -
	//Post:	i.p. contains n new tiles with value 2 or 4 with probabilities
	//		P(2) = 0.9 and P(4) = 0.9). If _freeCells < n only _freeCells tiles
	//		are added.
	void addTiles(int n);

	void slide(int start, int step);

	void merge(int start, int step);

	bool mergeCheck(int start, int step);

	bool gameOverCheck();

	void updateScore(int val);

	void updateMax(int val);

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

	bool push(char direction);
	//Pre: 'direction' is one of these characters: 'u'(up), 'd'(down), 'l'(left), 'r'(right)
	//Post: Every tile has been moved in the 'direction' direction until merging with an equivalent tile, stopping at a different value tile or reaching the edge

	/* Consultores */

	bool gameOver();

	vector<int> getGrid();

	/* Entrada/Sortida */

	void print();

};
