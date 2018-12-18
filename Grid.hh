#ifndef Grid_hh
#define Grid_hh

#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

class Grid{

//Tipus de modul: dades
//Descripcio del tipus:

private:

	vector<int> cells;
	vector<int> heurWeights;
	int _size;
	int _nCells;
	int _nFreeCells;
	bool _moved;
	bool _gameOver;
	int _max;			//Maximum value currently on the board.
	int _score;			//(number of merges)*(value of the resulting tile)

	/**
	*	Slides all the tiles of the row or column specified by start and step
	*	in the specified direction.
	*/
	void slide(int start, int step);

	/**
	*	Merges any consecutive tiles with the same value for the row or column
	*	and direction specified by start and step.
	*/
	void merge(int start, int step);

	/**
	*	Returns true if the row or column specified by start and step contains
	*	two or more tiles such that they can merge within a single move.
	*/
	bool mergeCheck(int start, int step);

	/**
	*	Checks if there are any moves available and returns true if there are
	*	and false otherwise. Updates _gameOver consequently.
	*/
	bool gameOverCheck();

	/**
	*	Adds val to the current score. and updates the maximum value with val.
	*/
	void updateScore(int val);

	/**
	*	Updates the maximum value on the board comparing it to val.
	*/
	void updateMax(int val);

	/**
	*	Builds the heuristic weights matrix.
	*/
	void buildHeurWeights();

	/**
	*	Prints the top edge of the board.
	*/
	void printTop() const;

	/**
	*	Prints the horizontal row separator of the board.
	*/
	void printMid() const;

	/**
	*	Prints the bottom edge of the board.
	*/
	void printBottom() const;

	/**
	*	Conversion from char to int dir.
	*/
	static int charToDir(char c){
		switch(c){
			case 'w': return 0;		//Up
			case 'a': return 1;		//Left
			case 's': return 2;		//Down
			case 'd': return 3;		//Right
			default: return 0;
		}
	}

	/**
	*	Returns the integer power x^p.
	*/
	int pow(int x, int p){
		if (p == 0) return 1;
		if (p == 1) return x;

		int tmp = pow(x, p/2);
		if (p%2 == 0) return tmp * tmp;
		else return x * tmp * tmp;
	}

public:

	/* Constructores */

	Grid(int size = 4);

	Grid(const Grid& g) : cells(g.cells), heurWeights(g.heurWeights),
	_size(g._size), _nCells(g._nCells), _nFreeCells(g._nFreeCells),
	_moved(g._moved), _gameOver(g._gameOver), _max(g._max), _score(g._score){};

	/* Modificadores */

	/**
	*	Adds a Tile with value v at the nth free position. Returns false if the
	*	board wasn't altered and true otherwise.
	*/
	bool addTile(int v, int n);

	/**
	*	Pre: -
	*	Post: i.p. contains a new tile with value 2 or 4 with probabilities
	*	P(2) = 0.9 and P(4) = 0.1). Returns false if the board wasn't
	*	altered and true otherwise.
	*/
	bool addRandomTile();

	/**
	*	Pre: 0 <= dir < 4
	*	Post: Every tile has been moved in the dir direction until merging
	*	with an equivalent tile, stopping at a different value tile or
	*	reaching the edge. Returns false if the board wasn't altered and
	*	true otherwise.
	*/
	bool move(int dir);

	/**
	*	Pre: dir is one of these characters: 'w'(up), 's'(down),
	*	'a'(left), 'd'(right).
	*	Post: Every tile has been moved in the dir direction until merging
	*	with an equivalent tile, stopping at a different value tile or
	*	reaching the edge. Returns false if the board wasn't altered and
	*	true otherwise.
	*/
	bool move(char dir);

	/**
	*	Restarts the game.
	*/
	void reset();

	/* Consultores */

	/**
	*	Returns true if there are no possible moves left, false otherwise.
	*/
	bool gameOver();

	/**
	*	Returns the heuristic value of the Grid.
	*/
	int getHeur() const;

	/**
	*	Returns the score.
	*/
	int getScore() const;

	/**
	*	Returns the max value on board.
	*/
	int getMax() const;

	/**
	*	Returns the number of free cells in the grid.
	*/
	int getFreeCells() const;

	/* Entrada/Sortida */

	/**
	*	Prints the grid to standard output.
	*/
	void print() const;

};

#endif
