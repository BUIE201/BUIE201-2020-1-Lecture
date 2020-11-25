#include "Graph.h"
#include "Node.h"
#include "Arc.h"

#include <vector>
#include <map>

using namespace std;

Arc::Arc(Node* F, Node* T, int d, Graph& g) : FromNode(F), ToNode(T), pG(&g), Distance(d)
{
	g.AddArc(F, T, this);
	F->AddSuccessor(T);
}
