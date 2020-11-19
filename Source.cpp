#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ShortestPathLength(int FromNode, int ToNode, map< pair<int, int>, int >& Distance, vector< vector<int> >& Successors)
{
	// Simplified version of Bellman-Ford algorithm : Valid for DAGs with positive distances.
	// No exception handling is implemented.

	if (FromNode == ToNode)
		return 0;

	if (Successors.empty())
		return INT_MAX;

	int MinLength = -1;
	for (int SuccessorNode : Successors[FromNode])
	{
		int dist = 0;
		auto it = Distance.find({ SuccessorNode, ToNode });
		if (it != Distance.end())
		{
			dist = it->second;
		}
		else
		{
			dist = ShortestPathLength(SuccessorNode, ToNode, Distance, Successors);
			Distance.emplace(pair<int, int>(SuccessorNode, ToNode), dist);
		}

		auto PL = Distance[{FromNode, SuccessorNode}] + dist;
		if (MinLength < 0)
			MinLength = PL;
		else if (PL < MinLength)
			MinLength = PL;
	}
	return MinLength;
}


int main()
{
	map< pair<int, int>, int > Distance =
	{
		// {fromnode, tonode}, distance

		{{0, 1}, 5},
		{{1, 2}, 4},
		{{1, 3}, 2},
		{{2, 3}, 5},
		{{3, 4}, 4},
		{{3, 5}, 2},
		{{4, 5}, 1}
	};
	vector< vector<int> > Successors =
	{
		// vector of successor nodes

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