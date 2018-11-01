#include "Tile.hh"

/* Constructores */

Tile::Tile(){
	empty = true;
	value = 0;
}

/* Destructora per defecte */

Tile::~Tile(){}

/* Modificadores */

bool Tile::start(){
	bool a = empty;
	if(a){
		value = (rand() % 10) == 9 ? 4 : 2;
		empty = false;
	}
	return a;
}

void Tile::kill(){
	empty = true;
	value = 0;
}

void Tile::merge(){
	value *= 2;	
}

/* Consultores */

bool Tile::operator== (const Tile & rhs) const{
	return value == rhs.value;
}

int Tile::getValue(){
	return value;
}

bool Tile::isEmpty(){
	return empty;
}

/* Entrada/Sortida */
