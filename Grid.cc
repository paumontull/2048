#include "Grid.hh"

/* Constructores */

Grid::Grid(int size) : _size(size){

	_nCells = _nFreeCells = size*size;

	_moved = _gameOver = false;

	cells = vector<int>(_nCells);
	heurWeights = vector<int>(_nCells);
	buildHeurWeights();

	srand(time(NULL));
	_max = _score = 0;

	addRandomTile();
	addRandomTile();
	for(int i = 0; i < _nCells; ++i) updateMax(cells[i]);
}

/* Modificadores */

bool Grid::addTile(int v, int n){
	if(_nFreeCells > 0){

		int i = 0;
		while(n >= 0){
			if(cells[i] == 0) --n;
			++i;
		}

		cells[i - 1] = v;
		--_nFreeCells;
		return true;
	}
	gameOverCheck();
	return false;
}

bool Grid::addRandomTile(){
	return addTile(((rand() % 10) == 9 ? 4 : 2), rand() % _nFreeCells);
}

bool Grid::move(int dir){
	_moved = false;
	if(not _gameOver){
		switch (dir) {
			case 0:
				for(int i = 0; i < _size; ++i){
					slide(i, _size);
					merge(i, _size);
					slide(i, _size);
				}
				break;
			case 1:
				for(int i = 0; i < _size; ++i){
					slide(i * _size, 1);
					merge(i * _size, 1);
					slide(i * _size, 1);
				}
				break;
			case 2:
				for(int i = 0; i < _size; ++i){
					slide(_nCells - 1 - i, -_size);
					merge(_nCells - 1 - i, -_size);
					slide(_nCells - 1 - i, -_size);
				}
				break;
			case 3:
				for(int i = 0; i < _size; ++i){
					slide(_nCells - 1 - i * _size, -1);
					merge(_nCells - 1 - i * _size, -1);
					slide(_nCells - 1 - i * _size, -1);
				}
				break;
		}
		if(_nFreeCells == 0) gameOverCheck();
	}
	return _moved;
}

bool Grid::move(char dir){
	return move(charToDir(dir));
}

void Grid::reset(){
	_nCells = _nFreeCells = _size*_size;

	_moved = _gameOver = false;

	cells = vector<int>(_nCells, 0);
	_max = _score = 0;

	addRandomTile();
	addRandomTile();
	for(int i = 0; i < _nCells; ++i) updateMax(cells[i]);
}

void Grid::slide(int start, int step){
	vector<int> filtered;

	bool firstZero = false;
	int curr = start;
	for(int i = 0; i < _size; ++i){
		if(cells[curr] != 0){
			filtered.push_back(cells[curr]);
			cells[curr] = 0;
			if(firstZero) _moved = true;
		}
		else if(not firstZero) firstZero = true;

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
			cells[curr] *= 2;
			updateScore(cells[curr]);
			cells[curr + step] = 0;
			++_nFreeCells;
		}
		curr += step;
	}
}

bool Grid::mergeCheck(int start, int step){
	int curr = start;
	for(int i = 0; i < _size - 1; ++i){
		if(cells[curr] == cells[curr + step]){
			return true;
		}
		curr += step;
	}
	return false;
}

bool Grid::gameOverCheck(){
	if(_nFreeCells != 0) return false;
	for(int i = 0; i < _size; ++i) if(mergeCheck(i, _size)) return false;
	for(int i = 0; i < _size; ++i) if(mergeCheck(_nCells - 1 - i, -_size)) return false;
	for(int i = 0; i < _size; ++i) if(mergeCheck(i * _size, 1)) return false;
	for(int i = 0; i < _size; ++i) if(mergeCheck(_nCells - 1 - i * _size, -1)) return false;
	return _gameOver = true;
}

void Grid::updateScore(int val){
	_score += val;
	updateMax(val);
}

void Grid::updateMax(int val){
	if(val > _max) _max = val;
}

void Grid::buildHeurWeights(){
	int x = _size * _size - 1;
	int j = 0;
	int step = 1;
	for(int i = 0; i < _size; ++i){
		while(j >= _size * i and j < _size * i + _size){
			heurWeights[j] = pow(2, x);
			j += step;
			--x;
		}
		j += _size - step;
		step *= -1;
	}
}

/* Consultores */

bool Grid::gameOver(){
	return gameOverCheck();
}

int Grid::getHeur() const{
	int x = 0;
	for(int i = 0; i < _size * _size; ++i){
		x += heurWeights[i] * cells[i];
	}
	return x;
}

int Grid::getScore() const{
	return _score;
}

int Grid::getMax() const{
	return _max;
}

int Grid::getFreeCells() const{
	return _nFreeCells;
}

/* Entrada/Sortida */

void Grid::printTop() const{
	cout << "┌";
	for(int i = 1; i < _size; ++i) cout << "──────┬";
	cout << "──────┐" << endl;

	cout << "│";
	for(int i = 1; i < _size; ++i) cout << "      │";
	cout << "      │" << endl;
}

void Grid::printMid() const{
	cout << "├";
	for(int i = 1; i < _size; ++i) cout << "──────┼";
	cout << "──────┤" << endl;

	cout << "│";
	for(int i = 1; i < _size; ++i) cout << "      │";
	cout << "      │" << endl;
}

void Grid::printBottom() const{
	cout << "└";
	for(int i = 1; i < _size; ++i) cout << "──────┴";
	cout << "──────┘" << endl;
}

void Grid::print() const{
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
