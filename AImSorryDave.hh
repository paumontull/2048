#ifndef AImSorryDave_hh
#define AImSorryDave_hh

#include "Player.hh"
#include <limits>

class AImSorryDave : public Player{
private:

	int min(int i, int j){
		return (i < j) ? i : j;
	}

	int max(int i, int j){
		return (i > j) ? i : j;
	}

	/**
	*	Conversion from int to char dir.
	*/
	static char intToChar(int m){
		switch(m){
			case 0: return 'w';		//Up
			case 1: return 'a';		//Left
			case 2: return 's';		//Down
			case 3: return 'd';		//Right
			default: return 'w';
		}
	}

public:

	char move(const Grid& g);

};

#endif
