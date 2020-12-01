#include "Graph.h"
#include "Node.h"
#include "Arc.h"


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

