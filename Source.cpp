#include "Graph.h"
#include "Node.h"
#include "Arc.h"

#include<iostream>
#include<fstream>

int main()
{
	Graph g;

	ifstream is("input.txt");

	int nNodes;
	is >> nNodes;

	for (int i = 0; i < nNodes; i++)
	{
		int ID;
		is >> ID;
		new Node(ID, g);
	}

	int nArcs;
	is >> nArcs;

	for (int i = 0; i < nArcs; i++)
	{
		int FromNodeID;
		int ToNodeID;
		int Distance;

		is >> FromNodeID >> ToNodeID >> Distance;
		Node* pFromNode = g.GetNode(FromNodeID);
		Node* pToNode = g.GetNode(ToNodeID);
		if (pFromNode && pToNode)
			new Arc(pFromNode, pToNode, Distance, g);
	}

	//auto pSourceNode = g.GetSourceNode();
	//auto pTerminationNode = g.GetTerminationNode();

	//if (pSourceNode && pTerminationNode)
	//	cout << pSourceNode->ShortestPathLength(pTerminationNode);

	return 1;
}

