#include "AImSorryDave.hh"

int miniMax(int depth, int alpha, int beta, bool isMaximizer, unique_ptr<MiniMaxNode> node){
	if(depth == 0){
		return node->getGrid.getHeur();
	}
	else{
		if(isMaximizer){

			int maxi = numeric_limits<int>::max();

			for(int i = 0; i < 4; ++i){
				Grid g = node->getGrid();
				if(g.move(m)){
					unique_ptr child = make_unique<MiniMaxNode>(g);

					node->appendChild(child);

					maxi = max(maxi, miniMax(depth - 1, alpha, beta, false, child));

					return maxi;
				}
			}
		}
		else{
			for(int i = 0; i < node->getGrid().getFreeCells(); ++i){
				Grid g = node->getGrid();
				
			}
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
