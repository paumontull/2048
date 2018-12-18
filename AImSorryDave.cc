#include "AImSorryDave.hh"

int miniMax(int depth, int alpha, int beta, bool isMaximizer, Grid g){
	if(depth == 0 or g.gameOver()){
		return g.getHeur();
	}
	else if(isMaximizer){
		int v = numeric_limits<int>::min();

		for (int i = 0; v < beta and i < 4; ++i){
			Grid h = Grid(g);
			if(h.move(i)){
				int w = miniMax(depth - 1, alpha, beta, false, h);
				if(v < w) v = w;
				alpha = max(alpha, v);
			}
		}
		return v;
	}
	else{
		int v = numeric_limits<int>::max();

		Grid h = Grid(g);
		int n = h.getFreeCells();
		int i = 0;
		bool alt = true;

		while(v > alpha and i < n){
			if(alt) h.addTile(2, i);
			else{
				h.addTile(4, i);
				++i;
			}

			v = min(v, miniMax(depth - 1, alpha, beta, true, h));
			beta = min(beta, v);

			alt = not alt;
			h = Grid(g);
		}
		return v;
	}
}

char AImSorryDave::move(const Grid& g){
	int alpha, beta, v, m;
	v = alpha = numeric_limits<int>::min();
	beta = numeric_limits<int>::max();
	m = -1;

	for (int i = 0; i < 4; ++i){
		Grid h = Grid(g);
		if(h.move(i)){
			int w = max(v, miniMax(6, alpha, beta, false, h));
			if(v < w){
				v = w;
				m = i;
			}
			alpha = max(alpha, v);
		}
	}

	return intToChar(m);
}
