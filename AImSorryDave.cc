#include "AImSorryDave.hh"

void buildTree(int currDepth, int depth, unique_ptr<MiniMaxNode> node){
	if(currDepth == depth);
	else{
		if(isMaximizer){
			Grid g = node->getGrid();
			g.push('w');
			node->appendChild(make_unique<MiniMaxNode>(g));

			g = node->getGrid();
			g.push('a');
			node->appendChild(make_unique<MiniMaxNode>(g));

			g = node->getGrid();
			g.push('s');
			node->appendChild(make_unique<MiniMaxNode>(g));

			g = node->getGrid();
			g.push('s');
			node->appendChild(make_unique<MiniMaxNode>(g));
		}
		else{
			
		}
	}
}

char AImSorryDave::move(const Grid& g){

	g.print();

	root = make_unique<MiniMaxNode>(g);

	int depth = 4;

	for(int i = 0; i <= depth; ++i){

	}


	return 'w';
}
