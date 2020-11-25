#include <vector>
#include <map>

using namespace std;

//Forward declaration
class Graph;
class Arc;

class Node
{
	int ID;
	vector<Node*> Successors;
	map<Node*, int> Cache;
	Graph* pG;

public:
	// Constructor
	Node(int IDIn, Graph& g);
	void AddSuccessor(Node* p);
	int GetShortestPathFromCache(Node* ToNode);
	void RegisterShortestPathFromCache(Node* ToNode, int dist);
	int ShortestPathLength(Node* ToNode);
};