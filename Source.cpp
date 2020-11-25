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
	map<pair<Node*, Node*>, Arc*> Arcs;

public:
	void AddNode(Node* p);
	void AddArc(Node* FromNode, Node* ToNode, Arc* p);
	Arc* GetArc(Node* FromNode, Node* ToNode);
};

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

class Arc
{
	Node* FromNode;
	Node* ToNode;
	Graph* pG;

	int Distance;

public:
	Arc(Node* F, Node* T, int d, Graph& g);
	int GetDistance() { return Distance; }
};


void Graph::AddNode(Node* p)
{
	Nodes.push_back(p);
}
void Graph::AddArc(Node* FromNode, Node* ToNode, Arc* p)
{
	Arcs.emplace(make_pair(FromNode, ToNode), p);
}
Arc* Graph::GetArc(Node* FromNode, Node* ToNode)
{
	auto it = Arcs.find({ FromNode, ToNode });
	if (it == Arcs.end())
		return nullptr;
	return it->second;
}

Node::Node(int IDIn, Graph& g) : ID(IDIn), pG(&g)
{
	g.AddNode(this);
}
void Node::AddSuccessor(Node* p)
{
	Successors.push_back(p);
}
int Node::GetShortestPathFromCache(Node* ToNode)
{
	auto it = Cache.find(ToNode);
	if (it == Cache.end())
		return -1;
	return it->second;
}
void Node::RegisterShortestPathFromCache(Node* ToNode, int dist)
{
	Cache.emplace(ToNode, dist);
}

int Node::ShortestPathLength(Node* ToNode)
{
	// Simplified version of Bellman-Ford algorithm : Valid for DAGs with positive distances.
	// Dynamic programming

	if (this == ToNode)
		return 0;

	if (Successors.empty())
		return INT_MAX;

	int MinLength = INT_MAX;
	for (Node* SuccessorNode : Successors)
	{
		// memoization, cache
		int dist = 0;
		int SPL = SuccessorNode->GetShortestPathFromCache(ToNode);
		if (SPL > 0)
		{
			dist = SPL;
		}
		else
		{
			dist = SuccessorNode->ShortestPathLength(ToNode);
			SuccessorNode->RegisterShortestPathFromCache(ToNode, dist);
		}

		if (dist != INT_MAX)
		{
			Arc* pA = pG->GetArc(this, SuccessorNode);
			auto PL = pA->GetDistance() + dist;
			if (PL < MinLength)
				MinLength = PL;
		}
	}
	return MinLength;
}

Arc::Arc(Node* F, Node* T, int d, Graph& g) : FromNode(F), ToNode(T), pG(&g), Distance(d)
{
	g.AddArc(F, T, this);
	F->AddSuccessor(T);
}



int main()
{
	Graph g;

	Node n0(0, g);
	Node n1(1, g);
	Node n2(2, g);
	Node n3(3, g);
	Node n4(4, g);
	Node n5(5, g);

	Arc a0(&n0, &n1, 5, g);
	Arc a1(&n1, &n2, 4, g);
	Arc a2(&n1, &n3, 2, g);
	Arc a3(&n2, &n3, 3, g);
	Arc a4(&n3, &n4, 4, g);
	Arc a5(&n3, &n5, 2, g);
	Arc a6(&n4, &n5, 1, g);

	int pathlength = n0.ShortestPathLength(&n5);

	return 1;
}

