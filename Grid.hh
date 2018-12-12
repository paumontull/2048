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

	//Pre:	'direction' is one of these characters: 'w'(up), 's'(down),
	//		'a'(left), 'd'(right).
	//Post:	Every tile has been moved in the 'direction' direction until merging
	//		with an equivalent tile, stopping at a different value tile or
	//		reaching the edge. Returns false if the board wasn't altered and
	//		true otherwise.
	bool push(char direction);

	//Pre: -
	//Post:	i.p. contains a new tile with value 2 or 4 with probabilities
	//		P(2) = 0.9 and P(4) = 0.1). Returns false if the board wasn't
	//		altered and true otherwise.
	bool addTile();

	/* Consultores */

	bool gameOver();

	vector<int> getGrid();

	/* Entrada/Sortida */

	void print();

};
