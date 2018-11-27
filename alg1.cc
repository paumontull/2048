#include "Grid.hh"
using namespace std;

int main(){
	Grid g(4);
	while(!g.gameOver()){
		g.print();
		while(g.push('w')) g.print();
		if(!g.push('d')){
			if(!g.push('a')) g.push('s');
		}
	}
	g.print();
}
