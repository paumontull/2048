class MiniMaxNode{
private:

	Grid _g;
	vector<unique_ptr<MiniMaxNode>> children;

public:

	MiniMaxNode(const Grid& g);

	void appendChild(unique_ptr<MiniMaxNode>);

}
