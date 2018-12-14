#include "Player.hh"

class Human : public Player{
public:

	char move(const Grid& g){

		g.print();

		char direction;
		cin >> direction;
		return direction;

	};

};
