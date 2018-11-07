#include "Grid.hh"

/* Constructores */

Grid::Grid(int size) : _size(size){

	_nCells = _freeCells = size*size;

	_moved = false;

	cells = vector<int>(_nCells);

	srand(time(NULL));

	addTiles(2);
	for(int i = 0; i < _nCells; ++i) updateMax(cells[i]);
}

void Grid::addTiles(int n){
	for(int i = 0; i < n and _freeCells > 0; ++i){
		int nthFreeCell = rand() % _freeCells;
		int pos = 0;

		for(int j = 0; nthFreeCell >= 0 and j < _nCells; ++j){
			if(cells[j] == 0){
				pos = j;
				--nthFreeCell;
			}
		}

		cells[pos] = ((rand() % 10) == 9 ? 4 : 2);
		--_freeCells;
	}
}

/* Destructora per defecte */

Grid::~Grid(){}

/* Modificadores */

void Grid::slide(int start, int step){
	vector<int> filtered;

	bool firstZero = false;
	int curr = start;
	for(int i = 0; i < _size; ++i){
		if(!cells[curr] == 0){
			filtered.push_back(cells[curr]);
			cells[curr] = 0;
			if(firstZero) _moved = true;
		}
		else if(!firstZero) firstZero = true;

		curr += step;
	}

	curr = start;
	for(int i = 0; i < filtered.size(); ++i){
		cells[curr] = filtered[i];
		curr += step;
	}
}

void Grid::merge(int start, int step){
	int curr = start;
	for(int i = 0; i < _size - 1; ++i){
		if(cells[curr] == cells[curr + step] and cells[curr] != 0){
			_moved = true;
			updateScore(cells[curr] *= 2);
			cells[curr + step] = 0;
			++_freeCells;
		}
		curr += step;
	}
}

bool Grid::push(char direction){
	_moved = false;
	if(direction == 'u'){
		for(int i = 0; i < _size; ++i){
			slide(i, _size);
			merge(i, _size);
			slide(i, _size);
		}
	}
	else if(direction == 'd'){
		for(int i = 0; i < _size; ++i){
			slide(_nCells - 1 - i, -_size);
			merge(_nCells - 1 - i, -_size);
			slide(_nCells - 1 - i, -_size);
		}
	}
	else if(direction == 'l'){
		for(int i = 0; i < _size; ++i){
			slide(i * _size, 1);
			merge(i * _size, 1);
			slide(i * _size, 1);
		}
	}
	else if(direction == 'r'){
		for(int i = 0; i < _size; ++i){
			slide(_nCells - 1 - i * _size, -1);
			merge(_nCells - 1 - i * _size, -1);
			slide(_nCells - 1 - i * _size, -1);
		}
	}
	if(_moved) addTiles(1);
	return _moved;
}

void Grid::updateScore(int val){
	_score += val;
	updateMax(val);
}

void Grid::updateMax(int val){
	if(val > _max) _max = val;
}

/* Consultores */



/* Entrada/Sortida */

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

void Grid::print(){
	cout << endl << _max << "        " << _score << endl << endl;
	printTop();
	for(int i = 0; i < _size; ++i){
		for(int j = 0; j < _size; ++j){
			int num = cells[i * _size + j];
			string val = (num == 0) ? " " : to_string(num);
			cout << "│ " << std::right << setw(4) << val << ' ';
		}
		cout << "│" << endl;
		if(i < _size - 1) printMid();
	}
	printBottom();
}
