#pragma once

#include <vector>
#include <map>
#include <string>
#include<fstream>

using namespace std;

class Node;
class Arc;

class Graph
{
	Node* pSourceNode;
	Node* pTerminationNode;

	vector<Node*> Nodes;
	map<pair<Node*, Node*>, Arc*> Arcs;

	Node* GetNode(int NodeID);

	void LoadNodes(ifstream& is);
	void LoadArcs(ifstream& is);

	void LoadGraphFromFile(string& FileName);
public:
	Graph(string FileName);
	~Graph();

	void AddNode(Node* p);
	void AddArc(Node* FromNode, Node* ToNode, Arc* p);
	Arc* GetArc(Node* FromNode, Node* ToNode);

	Node* GetSourceNode() { return pSourceNode; }
	Node* GetTerminationNode() { return pTerminationNode; }

};

