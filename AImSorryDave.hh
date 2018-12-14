#include "Player.hh"
#include "MiniMaxTree.hh"
##include <limits>

class AImSorryDave : public Player{
private:

	unique_ptr<MiniMaxNode> root;

public:

	char move(const Grid& g);

};
