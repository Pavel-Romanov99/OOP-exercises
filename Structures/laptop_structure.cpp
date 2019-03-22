#include <iostream>
#include <string>
using namespace std;

struct Laptop
{
	int battery;
	int screen;
	string brand;
	string description;

	Laptop()
	{
		battery = 0;
		screen = 0;
		brand = "";
		description = "";
	}

	Laptop(int new_battery, int new_screen, string new_brand, string new_description)
	{
		battery = new_battery;
		screen = new_screen;
		brand = new_brand;
		description = new_description;
	}

	void read()
	{
		cout << "Battery: "; cin >> battery;
		cout << "Screen: "; cin >> screen;
		cin.ignore();
		cout << "Brand: "; getline(cin, brand);
		cout << "Description: "; getline(cin, description);
	}

	void print()
	{
		cout << "Battery: " << battery << endl;
		cout << "Screen: " << screen << endl;
		cout << "Brand: " << brand << endl;
		cout << "Description: " << description;
	}
};

int main()
{
	Laptop pavel;
	pavel.read();
	pavel.print();
}
