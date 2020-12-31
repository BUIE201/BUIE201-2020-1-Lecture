#include <iostream>

using namespace std;


class IntVector201
{
	int Capacity;
	int Size;
	int* pData;

	void Expand()
	{
		int NewCapacity = Capacity == 0 ? 10 : Capacity + (Capacity / 2);
		int* pNewData = new int[NewCapacity];
		for (int i = 0; i < size(); i++)
		{
			pNewData[i] = pData[i];
		}
		Capacity = NewCapacity;
		pData = pNewData;
	}

public:
	IntVector201() : pData(nullptr), Capacity(0), Size(0) {}
	IntVector201(int InitialSize, int DefaultValue = 0) : Capacity(InitialSize), Size(InitialSize)
	{
		pData = new int[Capacity];
		for (int i = 0; i < Size; i++)
		{
			pData[i] = DefaultValue;
		}
	}

	int capacity() { return Capacity; }
	int size() { return Size; }
	void push_back(int x)
	{
		if (Capacity <= Size)
			Expand();
		pData[Size] = x;
		Size++;
	}
	int& operator[](int i)
	{
		// See what happens if i is out of bounds. (i >= Capacity)
		// See what happens if return type is "int" instead of "int&".

		return pData[i];
	}

	friend ostream& operator<<(ostream& os, IntVector201& d);
};

ostream& operator<<(ostream& os, IntVector201& d)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (i > 0)
			os << ", ";
		os << d[i];
	}
	return os;
}

void main()
{
	IntVector201 v1;
	v1.push_back(3);
	v1.push_back(5);

	cout << v1 << endl;

	IntVector201 v2(1);
	v2[0] = 7;
	v2.push_back(8);

	cout << v2[0]<< endl;
}