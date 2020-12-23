#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class AIRCRAFT;

class AIRLINE
{
	string Name;
	map<string, int> AIRCRAFTsByBrand;
	vector<AIRCRAFT*> AIRCRAFTs;

public:
	AIRLINE(string NameIn) : Name(NameIn) {}
	void AddAircraft(AIRCRAFT* pA);
	void RegisterAircraftBrand(string Brand)
	{
		auto [it, inserted] = AIRCRAFTsByBrand.emplace(Brand, 1);
		if (!inserted)
			it->second++;
	}
	void Print();
};

class AIRCRAFT
{
	int id;
public:
	AIRCRAFT(int idIn) : id(idIn) {}

	virtual void Print() 
	{
		cout << id;
	}
	virtual void RegisterBrandToAirline(AIRLINE* pAL) = 0;
};

class BOEING: public AIRCRAFT
{
public:

	BOEING(int id) : AIRCRAFT(id) 
	{
	}
	void RegisterBrandToAirline(AIRLINE* pAL)
	{
		pAL->RegisterAircraftBrand("BOEING");
	}
};

class AIRBUS : public AIRCRAFT
{
public:

	AIRBUS(int id) : AIRCRAFT(id)
	{
	}
	void RegisterBrandToAirline(AIRLINE* pAL)
	{
		pAL->RegisterAircraftBrand("AIRBUS");
	}
};

void AIRLINE::AddAircraft(AIRCRAFT* pA)
{
	AIRCRAFTs.push_back(pA);
	pA->RegisterBrandToAirline(this);
}

void AIRLINE::Print()
{
	cout << Name << " has ";
	for (auto [Brand, count] : AIRCRAFTsByBrand)
	{
		cout << count << " " << Brand << " and ";
	}
	cout << "aircrafts. IDs of the aircraft are: ";
	for (auto pA : AIRCRAFTs)
	{
		pA->Print();
		cout << " ";
	}
}

int main()
{
	AIRLINE* pAL = new AIRLINE("THY");
	pAL->AddAircraft(new BOEING(11)); // Parameter is the id of the aircraft.
	pAL->AddAircraft(new AIRBUS(22)); // Parameter is the id of the aircraft. 
	BOEING b(33);
	pAL->AddAircraft(&b);

	pAL->Print();// Output should read 
  // THY has 2 BOEING and 1 AIRBUS aircrafts. IDs of the aircraft are: 11 22 33

	return 1;
}
