#include "Grid.hh"

/* Constructores */

Grid::Grid(int size) : _size(size){
	
	_nCells = size*size;
	
	cells = vector<Tile>(_nCells);
	
	srand(time(NULL));
	
	addTiles(2);
}

void Grid::addTiles(int n){
	for(int i = 0; i < n; ++i){
		int pos = rand() % _nCells;
		while(!cells[pos].start()) pos++;
		--_nCells;
	}
}

/* Destructora per defecte */

Grid::~Grid(){}

/* Modificadores */

void Grid::push(char direction){
	int start;
	if(direction == 'u'){
		for(int i = 0; i < _size; ++i){
			start = _nCells - i - 1;
			iPush(start, -_size, 0, start);
		}
	} else if(direction == 'd'){
		for(int i = 0; i < _size; ++i){
			start = 0 + i;
			iPush(start, _size, start, _nCells - 1);
		}
	} else if(direction == 'l'){
		for(int i = 0; i < _size; ++i){
			start = _size + i * _size - 1;
			iPush(start, -1, i * _size, start);
		}
	} else if(direction == 'r'){
		for(int i = 0; i < _size; ++i){
			start = 0 + i * _size;
			iPush(start, 1, start, start + _size - 1);
		}
	}
	addTiles(1);
}

void Grid::iPush(int curr, int step, int min, int max){
	int next = curr + step;
	//print();
	if(next >= min and next <= max){
		if(cells[curr].isEmpty()) iPush(next, step, min, max);
		if(cells[next].isEmpty()){
			cells[next] = cells[curr];
			cells[curr].kill();
			iPush(next, step, min, max);
		}
		if(cells[next] == cells[curr]){
			cells[next].merge();
			cells[curr].kill();
			iPush(next, step, min, max);
		}
		iPush(next + step, step, min, max);
	}
}

/* Consultores */



/* Entrada/Sortida */

void Grid::print(){
	printTop();
	for(int i = 0; i < _size; ++i){
		for(int j = 0; j < _size; ++j){
			int num;
			string val = (num = cells[i * _size + j].getValue()) ? to_string(num) : " ";
			cout << "│ " << std::right << setw(4) << val << ' ';
		}
		cout << "│" << endl;
		if(i < _size - 1) printMid();
	}
	printBottom();
}

void Grid::printTop(){
	cout << "┌";
	for(int i = 1; i < _size; ++i) cout << "──────┬";
	cout << "──────┐" << endl;
	
	cout << "│";
	for(int i = 1; i < _size; ++i) cout << "      │";
	cout << "      │" << endl;
}

void Grid::printMid(){
	cout << "├";
	for(int i = 1; i < _size; ++i) cout << "──────┼";
	cout << "──────┤" << endl;
	
	cout << "│";
	for(int i = 1; i < _size; ++i) cout << "      │";
	cout << "      │" << endl;
}

void Grid::printBottom(){
	cout << "└";
	for(int i = 1; i < _size; ++i) cout << "──────┴";
	cout << "──────┘" << endl;
}
