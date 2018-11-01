#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Tile{

//Tipus de modul: dades
//Descripcio del tipus:

private:
	
	int value;
	bool empty;
	
public:
	
	/* Constructores */
	
	Tile();
	
	/* Destructora per defecte */
	
	~Tile();
	
	/* Modificadores */
	
	bool start();
	
	void kill();
	
	void merge();
	
	/* Consultores */
	
	bool operator== (const Tile & rhs) const;
	
	bool isEmpty();
	
	int getValue();
	
	/* Entrada/Sortida */
	
};
