#include "Graph.h"
#include "Node.h"
#include "Arc.h"


Graph::Graph(string FileName)
{
	LoadGraphFromFile(FileName);
}

Node* Graph::GetNode(int NodeID)
{
	if (NodeID < 0 || NodeID >= Nodes.size())
		return nullptr;

	return Nodes[NodeID];
}

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

void Graph::LoadNodes(ifstream& is)
{
	int nNodes;
	is >> nNodes;

	for (int i = 0; i < nNodes; i++)
	{
		int ID;
		is >> ID;
		new Node(ID, *this);
	}
}

void Graph::LoadArcs(ifstream& is)
{
	int nNodes;
	is >> nNodes;

	for (int i = 0; i < nNodes; i++)
	{
		int ID;
		is >> ID;
		new Node(ID, *this);
	}
}

void Graph::LoadGraphFromFile(string& FileName)
{
	ifstream is("input.txt");

	LoadNodes(is);
	LoadArcs(is);
}