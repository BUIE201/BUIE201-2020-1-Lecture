#include "Graph.h"
#include "Node.h"
#include "Arc.h"

#include<iostream>

int main()
{
	while (true)
	{
		Graph g("input.txt");

		auto pSourceNode = g.GetSourceNode();
		auto pTerminationNode = g.GetTerminationNode();

		if (pSourceNode && pTerminationNode)
			cout << pSourceNode->ShortestPathLength(pTerminationNode);
	}

	return 1;
}

