#include "Grid.hh"

/* Constructores */

Grid::Grid(int size) : _size(size){

	_nCells = _freeCells = size*size;

	cells = vector<Tile>(_nCells);

	srand(time(NULL));

	addTiles(2);
}

void Grid::addTiles(int n){
	for(int i = 0; i < n and _freeCells > 0; ++i){
		int pos = rand() % _freeCells;
		while(!cells[pos].start()){
			pos = (pos == _nCells - 1) ? 0 : pos + 1;
		}
		--_freeCells;
	}
}

/* Destructora per defecte */

Grid::~Grid(){}

/* Modificadores */

void Grid::push(char direction){
	if(direction == 'u'){
		for(int i = 0; i < _size; ++i){
			slide(_nCells - i - 1, -_size, 0, _nCells - i - 1);
			merge(i, _size, 0, _nCells - i -1);
			//slide(_nCells - i - 1, -_size, 0, _nCells - i - 1);
		}
	}
	/*

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
	}*/
	addTiles(1);
}

void Grid::slide(int curr, int step, int min, int max){
	if(curr + step >= min and curr + step <= max){
		if(cells[curr].isEmpty()) slide(curr + step, step, min, max);
		else if(cells[curr + step].isEmpty()){
			cells[curr + step] = cells[curr];
			cells[curr].kill();
			slide(curr + step, step, min, max);
		}
		else slide(curr + step, step, min, max);
	}
}

void Grid::merge(int curr, int step, int min, int max){
	if(curr + step >= min and curr + step <= max){
		if(cells[curr].isEmpty()) merge(curr + step, step, min, max);
		else if(cells[curr + step] == cells[curr]){
			cells[curr + step].kill();
			cells[curr].merge();
			cout << curr << ' ' << curr + step << endl;
			++_freeCells;
		}
		else merge(curr + step, step, min, max);
	}
}

// void Grid::iPush(int curr, int step, int min, int max){
// 	int next = curr + step;
// 	//print();
// 	if(next >= min and next <= max){
// 		if(cells[curr].isEmpty()) iPush(next, step, min, max);
// 		if(cells[next].isEmpty()){
// 			cells[next] = cells[curr];
// 			cells[curr].kill();
// 			iPush(next, step, min, max);
// 		}
// 		if(cells[next] == cells[curr]){
// 			cells[next].merge();
// 			cells[curr].kill();
// 			iPush(next, step, min, max);
// 		}
// 		iPush(next + step, step, min, max);
// 	}
// }

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
