#include "Grid.hh"
using namespace std;

int main(){
	Grid g(4);
	g.print();

	char direction;
	while(cin >> direction){
		if(g.push(direction)) g.addTile();
		g.print();
	}
}
