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

// [return type or void] [function name] ( optional list of parameters)
void f()
{
	cout << "f";
}

int g(int x)
{
	return x + 1;
}



void main()
{
	f();
	cout << g(5);

	cout << sizeof(int) << " " << sizeof(double) << " " << sizeof(long long);

	//vector<int> v = { 1, 3, 5, 8, 11, 15 };
	//cout << " FindSimpleWithIndexedForLoop found: " << FindSimpleWithIndexedForLoop(v, 17);
}