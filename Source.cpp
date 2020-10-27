#include <iostream>
#include <vector>

using namespace std;

int FindSimpleWithIndexedForLoop(vector<int>& v, int ValueToFind)
{
	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] == ValueToFind)
			return j;
	}
	return -1;
}

void main()
{
	vector<int> v = { 1, 3, 5, 8, 11, 15 };
	cout << " FindSimpleWithIndexedForLoop found: " << FindSimpleWithIndexedForLoop(v, 17);
}