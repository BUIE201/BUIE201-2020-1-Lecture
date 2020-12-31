#include <iostream>
#include <vector>

using namespace std;


class MyData
{
	string Name;
	int i;

public:
	MyData() : i(-1) {}
	MyData(int x, string NameIn) : i(x), Name(NameIn) {}
	MyData(int x) : i(x) {}

	static MyData null() { return MyData(); }
	bool IsNull() { return i == -1; }

	bool operator==(MyData& d)
	{
		return i == d.i;
	}
	friend ostream& operator<<(ostream& os, MyData& d);
};

ostream& operator<<(ostream& os, MyData& d)
{
	if (d.IsNull())
		os << "null";
	else
		os << d.Name << ":" << d.i;
	return os;
}

template <typename T> class ListNode
{
public:
	T data;
	shared_ptr<ListNode> Next;

	ListNode(T d) : data(d), Next(nullptr) {}
	bool operator==(ListNode& o)
	{
		return data == o.data;
	}
};

template <typename T> class List
{
	shared_ptr< ListNode<T> > Head{ nullptr };
	shared_ptr< ListNode<T> > Tail{ nullptr };

	void InsertToListAsHead(shared_ptr< ListNode<T> > NewListNode)
	{
		if (Head)
			NewListNode->Next = Head;
		else
			Tail = NewListNode;

		Head = NewListNode;
	}

	void InsertToListAsTail(shared_ptr< ListNode<T> > NewListNode)
	{
		if (Tail)
			Tail->Next = NewListNode;
		else
			Head = NewListNode;

		Tail = NewListNode;
	}

	void PrintList(shared_ptr< ListNode<T> > LocalHead)
	{
		if (!LocalHead)
			return;

		if (LocalHead != Head)
			cout << " -> ";
		cout << LocalHead->data;

		PrintList(LocalHead->Next);
	}

	void DeleteNodeWithTwoChildren(shared_ptr< ListNode<T> >& q, shared_ptr< ListNode<T> >& p)
	{
		if (p->Right)
		{
			DeleteNodeWithTwoChildren(q, p->Right);
			return;
		}

		p->data = q->data;
		q = p;
		p = p->Left;
	}

	void DeleteNodeFromList(shared_ptr< ListNode<T> > n, T d)
	{
		shared_ptr< ListNode<T> > ProspectNode = (n == nullptr ? Head : n->Next);

		if (ProspectNode->data == d)
		{
			if (n == nullptr)
				Head = Head->Next;
			else
				n->Next = (n->Next ? n->Next->Next : nullptr);
			return;
		}

		DeleteNodeFromList(ProspectNode, d);
	}

	T FindInList(shared_ptr< ListNode<T> > LocalHead, T d)
	{
		if (!LocalHead)
			return T::null();

		if (LocalHead->data == d)
			return LocalHead->data;

		return FindInList(LocalHead->Next, d);
	}

public:

	void InsertToHead(T d)
	{
		InsertToListAsHead(make_shared< ListNode<T> >(d));
	}
	void InsertToTail(T d)
	{
		InsertToListAsTail(make_shared< ListNode<T> >(d));
	}
	void Delete(T d)
	{
		DeleteNodeFromList(nullptr, d);
	}
	T Find(T d)
	{
		return FindInList(Head, d);
	}
	void Print()
	{
		PrintList(Head);
	}
};

void main()
{
	vector<pair<int, string>> v{ {3, "a"}, {5, "b"}, {2, "c"} };

	List<MyData> t;
	for (auto [i, name] : v)
	{
		t.InsertToHead({ i, name });
	}
	t.Print();

	cout << endl << endl;

	List<MyData> t2;
	for (auto [i, name] : v)
	{
		t2.InsertToTail({ i, name });
	}
	t2.Print();

	cout << endl << endl;

	t2.Delete(2);
	t2.Print();

	cout << endl << endl;

	auto x = t2.Find(3);
	cout << x;

	cout << endl << endl;

	auto y = t2.Find(30);
	cout << y;
}