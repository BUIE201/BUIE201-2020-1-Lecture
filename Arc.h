#pragma once

class Node;
class Graph;

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
