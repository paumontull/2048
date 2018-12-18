#include "AImStupid.hh"

char AImStupid::move(const Grid& g){
	Grid h = Grid(g);
	if(h.move('w')) return 'w';
	if(h.move('d')) return 'd';
	if(h.move('a')) return 'a';
	return 's';
}
