#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int n;
	cout << "Please insert the number of items: "; cin >> n;


	ofstream file("items.txt");
	if (file.fail())
	{
		cout << "Couldn't open the file !" << endl;
		exit(1);
	}

	string item;
	int power;
	for (int i = 0; i < n; i++)
	{
		cout << "Insert the item and it's power level. Item: "; cin >> item; cout << "Power level: "; cin >> power;
		file << item << " " << power << endl;
	}

	cout << "Please select which items to print: " << endl;
	cout << "Press 1 for positive items" << endl;
	cout << "Press 2 for negative items" << endl;
	cout << "Press 3 for neutral items" << endl;
	cout << "Press 4 to exit the program" << endl;

	int input;
	cin >> input;
	ifstream inFile("items.txt");
	while (input != 4)
	{
		if (input == 1)
		{
			while (inFile >> item >> power)
			{
				if (power > 0)
				{
					cout << item << " " << power << endl;
				}
			}
			break;
		}

		else if (input == 2)
		{
			while (inFile >> item >> power)
			{
				if (power < 0)
				{
					cout << item << " " << power << endl;
				}
			}
			break;
		}

		else if (input == 3)
		{
			while (inFile >> item >> power)
			{
				if (power == 0)
				{
					cout << item << " " << power << endl;
				}
			}
			break;
		}
	}
}