#include "Graph.h"
#include "Node.h"
#include "Arc.h"


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

