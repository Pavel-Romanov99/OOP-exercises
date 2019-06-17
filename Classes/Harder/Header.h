#pragma once
#include <string>
#include <iostream>
using namespace std;

class ElectricalDevice
{
protected:
	int energyConsump;
public:
	virtual void Alert() = 0;
	int get_energy();
};

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

};

class Scanner : public ElectricalDevice
{
private:
	int paper_price;
	bool paper_out;
public:
	Scanner();
	Scanner(int paper_price, bool paper_out);
	void Alert();
};

class Room : public ElectricalDevice
{
private:
	int capacity;
	int size;
	ElectricalDevice **list;
public:
	Room();
	~Room();
	Room(const Room &other);
	void addDevice(ElectricalDevice *);
	void Alert();
	int costNumberofDays(int x);
};