#include "Player.hh"
#include "Human.hh"
#include "AImStupid.hh"
#include "AImSorryDave.hh"
#include <fstream>
using namespace std;

int main(int argc, char** argv){
	if(argc != 2) return -1;

	Human h;
	AImStupid stupid;
	AImSorryDave dave;
	Player* player;

	if(argv[1][0] == '0'){
		player = &h;
	}
	else if(argv[1][0] == '1'){
		player = &stupid;
	}
	else if(argv[1][0] == '2'){
		player = &dave;
	}


	Grid g(4);
	for(int i = 0; i < 100; ++i){
		while(not g.gameOver()){
			if(g.move(player->move(g))){
				g.addRandomTile();
				//g.print();
			}
		}
		cout << g.getScore() << ' ' << g.getMax() << endl;
		g.reset();
	}
}
