#ifndef Human_hh
#define Human_hh

#include "Player.hh"

class Human : public Player{
public:

	char move(const Grid& g){
		char dir;
		cin >> dir;
		return dir;
	};

};

#endif
