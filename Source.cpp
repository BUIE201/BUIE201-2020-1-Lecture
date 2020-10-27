#include <iostream>
#include <vector>
#include <chrono>

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

int FindSimpleWithRangeForLoop(vector<int>& v, int ValueToFind)
{
	int i = 0;
	for (int x : v)
	{
		if (x == ValueToFind)
			return i;
		i++;
	}
	return -1;
}

int FindBinarySearch(vector<int>& v, int ValueToFind, int StartIndex, int EndIndex)
{
	if (EndIndex < StartIndex)
		return -1;

	int mid = (EndIndex + StartIndex) / 2;

	if (v[mid] == ValueToFind)
		return mid;

	if (v[mid] > ValueToFind)
		return FindBinarySearch(v, ValueToFind, StartIndex, mid - 1);

	//if (v[mid] < ValueToFind)
	return FindBinarySearch(v, ValueToFind, mid + 1, EndIndex);
}


void main()
{
	vector<int> v = { 1, 3, 5, 8, 11, 15 };


	auto start = chrono::system_clock::now();
	cout << " FindSimpleWithIndexedForLoop found: " << FindSimpleWithIndexedForLoop(v, 17);
	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	cout << " Elapsed Time: " << elapsed.count() << endl;

	start = chrono::system_clock::now();
	cout << " FindSimpleWithRangeForLoop found: " << FindSimpleWithRangeForLoop(v, 17);
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	cout << " Elapsed Time: " << elapsed.count() << endl;

	start = chrono::system_clock::now();
	cout << " FindBinarySearch found: " << FindBinarySearch(v, 17, 0, v.size() - 1);
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	cout << " Elapsed Time: " << elapsed.count() << endl;
}