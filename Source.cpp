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
	int& GetElement(int i)
	{
		return pData[i];
	}

	void Print(ostream& os)
	{
		for (int i = 0; i < Size; i++)
		{
			if (i > 0)
				os << ", ";
			os << pData[i];
		}
	}
};

void main()
{
	IntVector201 v1;
	v1.push_back(3);
	v1.push_back(5);

	v1.Print(cout);

	IntVector201 v2(1);
	v2.GetElement(0) = 7;
	v2.push_back(8);

	v1.Print(cout);

}