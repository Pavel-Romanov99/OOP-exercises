#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include "Header.h"
using namespace std;


int main()
{
	Printer a("1234", 100, false);
	Scanner b(120, true);
	ElectricalDevice *ptr1 = &a;
	ElectricalDevice *ptr2 = &b;

	//ElectricalDevice** room = new ElectricalDevice*[20];
	//room[0] = ptr1;
	//room[0]->Alert();

	Room room1;
	room1.addDevice(ptr1);
	room1.Alert();
}