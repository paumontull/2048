#include "MiniMaxNode.hh"

MiniMaxNode::MiniMaxNode(const Grid& g) : _g(g) {}

void MiniMaxNode::appendChild(unique_ptr<MiniMaxNode> child){
	children.push_back(child);
}
