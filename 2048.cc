#include "Player.hh"
#include "Human.hh"
#include "AImSorryDave.hh"
using namespace std;

int main(int argc, char** argv){
	if(argc != 2) return -1;

	Human h;
	AImSorryDave ai;
	Player* player;

	if(argv[1][0] == 'h'){
		player = &h;
	}
	else if(argv[1][0] == 'a'){
		player = &ai;
	}

	Grid g(4);

	while(not g.gameOver()){
		if(g.push(player->move(g))) g.addTile();
	}
}
