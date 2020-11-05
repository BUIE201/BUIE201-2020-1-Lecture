#include <iostream>
#include <vector>

using namespace std;

class STACK
{
	vector<int> Data;
	unsigned int TopIndex;

public:
	STACK(int EndIndicator) : TopIndex(0)
	{
		Data.push_back(EndIndicator);
	}
	~STACK()
	{
		if (IsEmpty())
			cout << "Stack is empty at destruction." << endl;
		else
			cout << "Stack has " << Data.size() - 1 << " objects at destruction." << endl;
		Data.clear();
	}
	void Push(int x)
	{
		TopIndex++;
		if (TopIndex < Data.size())
			Data[TopIndex] = x;
		else
			Data.push_back(x);
	}
	int Pop()
	{
		if (TopIndex == 0)
			return Data[TopIndex];

		return Data[TopIndex--];
	}
	bool IsEmpty() { return TopIndex == 0; }
	void Print()
	{
		cout << endl;
		cout << "=====" << endl;
		if (IsEmpty())
			cout << "Stack is empty." << endl;
		else
		{
			for (int i = TopIndex; i > 0; i--)
			{
				cout << Data[i] << endl;
			}
		}
		cout << "=====" << endl;
	}
};

int main()
{
	STACK s(99);

	int x;
	while (true)
	{
		cin >> x;
		if (x == 99)
			break;
		if (x == 999)
		{
			cout << endl << "Poped: " << s.Pop() << endl;
			s.Print();
		}
		else
		{
			s.Push(x);
			cout << endl << "Pushed: " << x << endl;
			s.Print();
		}
	}
	return 0;
}