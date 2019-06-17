#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>
#include "Header.h"
using namespace std;

class ElectricalDevice
{
protected:
	int energyConsump;
public:
	virtual void Alert() = 0;
	virtual ElectricalDevice* clone()const = 0;
	int get_energy();
};

//-----------------------------------------------------

class Printer : public ElectricalDevice
{
private:
	string id;
	int price;
	bool toner;
public:
	Printer();
	Printer(string id, int price, bool toner);
	void Alert();

	ElectricalDevice* clone()const
	{
		return new Printer(*this);
	}

};

void Printer::Alert()
{
	if (toner)
	{
		cout << "Printer number: " << id << " is out of toner" << endl;
	}
	else cout << "Printer number: " << id << " is working fine" << endl;
}

Printer::Printer()
{
	id = "0000";
	price = 0;
	toner = true;
}

Printer::Printer(string id, int price, bool toner)
{
	this->id = id;
	this->price = price;
	this->toner = toner;
}

int ElectricalDevice::get_energy()
{
	return this->energyConsump;
}


//------------------------------------------------

class Scanner : public ElectricalDevice
{
private:
	int paper_price;
	bool paper_out;
public:
	Scanner();
	Scanner(int paper_price, bool paper_out);
	void Alert();

	ElectricalDevice* clone()const
	{
		return new Scanner(*this);
	}
};

Scanner::Scanner()
{
	this->paper_price = 100;
	this->paper_out = true;
}

Scanner::Scanner(int paper_price, bool paper_out)
{
	this->paper_price = paper_price;
	this->paper_out = paper_out;
}

void Scanner::Alert()
{
	if (this->paper_out)
	{
		cout << "Scanner is out of paper!" << endl;
	}
	else cout << "Scanner still has paper!" << endl;
}

//--------------------------------------------------

class Room 
{
private:
	vector<ElectricalDevice*> devices;
public:

	void add_device(const ElectricalDevice &device)
	{
		devices.push_back(device.clone());
	}
	void Alert();
	int costNumberofDays(int x);
};


void Room::Alert()
{
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->Alert();
	}
}

int Room::costNumberofDays(int x)
{
	int sum = 0;
	for (int i = 0; i < devices.size(); i++)
	{
		sum += devices[i]->get_energy();
	}
	return sum * x;
}



int main()
{
	Printer a("1234", 100, false);
	Scanner b(120, true);

	Room room1;
	room1.add_device(a);
	room1.add_device(b);
	room1.Alert();
}