#include <iostream>
#include <string>
using namespace std;

int const car_size = 3;

struct car
{
	int mileage;
	double average_gas;
	string brand;
	string description;

	car()
	{
		mileage = 0;
		average_gas = 0.0;
		brand[0] = '\0';
		description[0] = '\0';
	}

	car(int newmileage, int new_average_gas, string newName, string newDescription)
	{
		mileage = newmileage;
		average_gas = new_average_gas;
		brand = newName;
		description = newDescription;
	}

	void read()
	{
		cout << "Mileage: "; cin >> mileage;
		cout << "Average gas : "; cin >> average_gas; 
		cin.ignore();
		cout << "Brand: "; getline(cin, brand);
		cout << "Description : "; getline(cin, description);
	}

	void print()
	{
		cout << "Mileage: " << mileage << endl;
		cout << "Average fuel consumption: " << average_gas << endl;
		cout << "Brand: " << brand << endl;
		cout << "Description: " << description << endl;
	}
};

int main()
{
	car *cars = new car[car_size];

	for (int i = 0; i < car_size; i++)
	{
		cars[i].read();
	}
	cout << endl;

	for (int j = 0; j < car_size; j++)
	{
		cout << "Car number : " << j << endl;
		cars[j].print();
		cout << endl;
	}

	delete[] cars;
}
