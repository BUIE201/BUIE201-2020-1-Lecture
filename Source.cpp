#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ShortestPathLength(int FromNode, int ToNode, map< pair<int, int>, int >& Distance, 
	vector< vector<int> >& Successors, 
	map< pair<int, int>, int >& Cache)
{
	// Simplified version of Bellman-Ford algorithm : Valid for DAGs with positive distances.
	// Dynamic programming

	if (FromNode == ToNode)
		return 0;

	if (Successors[FromNode].empty())
		return INT_MAX;

	int MinLength = INT_MAX;
	for (int SuccessorNode : Successors[FromNode])
	{
		// memoization, cache
		int dist = 0;
		auto it = Cache.find({ SuccessorNode, ToNode });
		if (it != Cache.end())
		{
			dist = it->second;
		}
		else
		{
			dist = ShortestPathLength(SuccessorNode, ToNode, Distance, Successors, Cache);
			Cache.emplace(pair<int, int>(SuccessorNode, ToNode), dist);
		}

		if (dist != INT_MAX)
		{
			auto PL = Distance[{FromNode, SuccessorNode}] + dist;
			if (PL < MinLength)
				MinLength = PL;
		}
	}
	return MinLength;
}

void CreateSuccessorsFromDistanceMap(map< pair<int, int>, int >& Distance, vector< vector<int> >& Successors)
{
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
		{{3, 5}, 200},
		{{4, 5}, 1}
	};
	map< pair<int, int>, int > Cache;

	vector< vector<int> > Successors;
	CreateSuccessorsFromDistanceMap(Distance, Successors);
	//	=
	//{
	//	 vector of successor nodes
	//	{1},
	//	{2, 3},
	//	{3},
	//	{4, 5},
	//	{5},
	//	{}
	//};

	auto d = ShortestPathLength(0, 5, Distance, Successors, Cache);
	cout << d;

	return 0;
}