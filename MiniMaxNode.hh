#include "Grid.hh"
#include <memory>

class MiniMaxNode{
private:

	Grid _g;
	vector<shared_ptr<MiniMaxNode>> children;

public:

	MiniMaxNode(const Grid g);

	void appendChild(shared_ptr<MiniMaxNode> child);

	Grid getGrid() const;

};
