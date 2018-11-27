#include "Grid.hh"
using namespace std;

int main(){
	Grid g(4);
	while(!g.gameOver()){
		g.print();
		g.push('w');
		g.push('d');
		g.push('s');
		g.push('a');
	}
	g.print();
}
