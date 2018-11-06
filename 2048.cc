#include "Grid.hh"
using namespace std;

int main(){
	Grid g(4);
	g.print();

	char direction;
	while(cin >> direction){
		g.push(direction);
		g.print();
	}
}
