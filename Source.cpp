#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ShortestPathLength(int FromNode, int ToNode, map< pair<int, int>, int>& Distance, vector< vector<int>>& Successors)
{
	// Simplified version of Bellman-Ford algorithm : Valid for DAGs with positive distances.
	// No exception handling is implemented.

	if (FromNode == ToNode)
		return 0;

	int MinDistance = -1;
	for (int Node : Successors[FromNode])
	{
		auto d = Distance[{FromNode, Node}] + ShortestPathLength(Node, ToNode, Distance, Successors);

		if (MinDistance < 0)
			MinDistance = d;
		else if (d < MinDistance)
			MinDistance = d;
	}
	return MinDistance;
}


int main()
{
	map< pair<int, int>, int> Distance =
	{
		{{0, 1}, 5},
		{{1, 2}, 4},
		{{1, 3}, 2},
		{{2, 3}, 5},
		{{3, 4}, 4},
		{{3, 5}, 2},
		{{4, 5}, 1}
	};
	vector< vector<int>> Successors =
	{
		{1},
		{2, 3},
		{3},
		{4, 5},
		{5},
		{}
	};

	auto d = ShortestPathLength(0, 5, Distance, Successors);
	cout << d;

	return 0;
}