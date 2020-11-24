#include <iostream>
#include <vector>
#include <map>

using namespace std;


//Forward declaration
class Node;
class Arc;

class Graph
{
	vector<Node*> Nodes;
	vector<Arc*> Arcs;

public:
	int ShortestPathLength(Node& FromNode, Node& ToNode)
	{
	}

	void AddNode(Node* p)
	{
		Nodes.push_back(p);
	}
	void AddArc(Arc* p)
	{
		Arcs.push_back(p);
	}
};

class Node
{
	int ID;

public:
	// Constructor
	Node(int IDIn, Graph& g) : ID(IDIn)
	{
		g.AddNode(this);
	}
};

class Arc
{
	Node* FromNode;
	Node* ToNode;

	int Distance;
public:
	Arc(Node* F, Node* T, int d, Graph& g) : FromNode(F), ToNode(T), Distance(d)
	{
		g.AddArc(this);
	}
};

int main()
{
	// Node is a class == a concept.
	// n1 is an object == an instance of class (concept) Node
	// Node does not physically exist. It is an idea.
	// n1 exists. It has an address in memory.

	Graph g;
	Node n1(0, g);
	Node n2(1, g);
	Node n3(2, g);
	Node n4(3, g);
	Node n5(4, g);
	Node n6(5, g);

	Arc a1(&n1, &n2, 10, g);
	Arc a2(&n1, &n3, 5, g);

	int pathlength = g.ShortestPathLength(n1, n6);

	return 1;
}





//
//
//int ShortestPathLength(int FromNode, int ToNode, map< pair<int, int>, int >& Distance, 
//	vector< vector<int> >& Successors, 
//	map< pair<int, int>, int >& Cache)
//{
//	// Simplified version of Bellman-Ford algorithm : Valid for DAGs with positive distances.
//	// Dynamic programming
//
//	if (FromNode == ToNode)
//		return 0;
//
//	if (Successors[FromNode].empty())
//		return INT_MAX;
//
//	int MinLength = INT_MAX;
//	for (int SuccessorNode : Successors[FromNode])
//	{
//		// memoization, cache
//		int dist = 0;
//		auto it = Cache.find({ SuccessorNode, ToNode });
//		if (it != Cache.end())
//		{
//			dist = it->second;
//		}
//		else
//		{
//			dist = ShortestPathLength(SuccessorNode, ToNode, Distance, Successors, Cache);
//			Cache.emplace(pair<int, int>(SuccessorNode, ToNode), dist);
//		}
//
//		if (dist != INT_MAX)
//		{
//			auto PL = Distance[{FromNode, SuccessorNode}] + dist;
//			if (PL < MinLength)
//				MinLength = PL;
//		}
//	}
//	return MinLength;
//}
//
//void CreateSuccessorsFromDistanceMap(map< pair<int, int>, int >& Distance, vector< vector<int> >& Successors)
//{
//	int MaxNode = 0;
//	for (auto it = Distance.begin(); it != Distance.end(); ++it)
//	{
//		auto p = it->first;
//
//		if (MaxNode < p.first)
//			MaxNode = p.first;
//		if (MaxNode < p.second)
//			MaxNode = p.second;
//	}
//	Successors.resize(MaxNode + 1);
//	for (auto it = Distance.begin(); it != Distance.end(); ++it)
//	{
//		auto p = it->first;
//		Successors[p.first].push_back(p.second);
//	}
//}
//
//int main()
//{
//	map< pair<int, int>, int > Distance =
//	{
//		// {fromnode, tonode}, distance
//
//		{{0, 1}, 5},
//		{{1, 2}, 4},
//		{{1, 3}, 2},
//		{{2, 3}, 5},
//		{{3, 4}, 4},
//		{{3, 5}, 200},
//		{{4, 5}, 1}
//	};
//	map< pair<int, int>, int > Cache;
//
//	vector< vector<int> > Successors;
//	CreateSuccessorsFromDistanceMap(Distance, Successors);
//	//	=
//	//{
//	//	 vector of successor nodes
//	//	{1},
//	//	{2, 3},
//	//	{3},
//	//	{4, 5},
//	//	{5},
//	//	{}
//	//};
//
//	auto d = ShortestPathLength(0, 5, Distance, Successors, Cache);
//	cout << d;
//
//	return 0;
//}