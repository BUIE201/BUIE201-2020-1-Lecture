#include "Graph.h"
#include "Node.h"
#include "Arc.h"



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
