#ifndef Player_hh
#define Player_hh

#include "Grid.hh"

class Player {
public:

	virtual char move(const Grid& g) = 0;

};

#endif
