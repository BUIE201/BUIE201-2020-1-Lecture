#include <iostream>

using namespace std;


template <typename T> class IntVector201
{
	int Capacity;
	int Size;
	T* pData;

	void Expand()
	{
		int NewCapacity = Capacity == 0 ? 10 : Capacity + (Capacity / 2);
		T* pNewData = new T[NewCapacity];
		for (int i = 0; i < size(); i++)
		{
			pNewData[i] = pData[i];
		}
		Capacity = NewCapacity;
		pData = pNewData;
	}

public:
	IntVector201() : pData(nullptr), Capacity(0), Size(0) {}
	IntVector201(int InitialSize, T DefaultValue) : Capacity(InitialSize), Size(InitialSize)
	{
		pData = new int[Capacity];
		for (int i = 0; i < Size; i++)
		{
			pData[i] = DefaultValue;
		}
	}

	int capacity() { return Capacity; }
	int size() { return Size; }
	void push_back(T x)
	{
		if (Capacity <= Size)
			Expand();
		pData[Size] = x;
		Size++;
	}
	T& operator[](int i)
	{
		// See what happens if i is out of bounds. (i >= Capacity)
		// See what happens if return type is "T" instead of "T&".

		return pData[i];
	}
};

void main()
{
	IntVector201<int> v1;
	v1.push_back(3);
	v1.push_back(5);

	IntVector201<int> v2(1, 0);
	v2[0] = 7;
	v2.push_back(8);

	cout << v2[0]<< endl;
}