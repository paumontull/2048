#include "MiniMaxNode.hh"

MiniMaxNode::MiniMaxNode(const Grid g) : _g(g) {}

void MiniMaxNode::appendChild(shared_ptr<MiniMaxNode> child){
	children.push_back(child);
}

Grid MiniMaxNode::getGrid() const{
	return _g;
}
