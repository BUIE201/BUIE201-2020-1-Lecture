#pragma once

#include <vector>
#include <map>

using namespace std;

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

