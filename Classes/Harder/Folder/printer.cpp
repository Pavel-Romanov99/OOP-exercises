#include "Header.h"

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
