#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class People
{
private:
	string name;
	int year;
public:
	People()
	{
		name = "";
		year = 0;
	}

	People(string name, int year)
	{
		this->name = name;
		this->year = year;
	}

	void set_name(string x)
	{
		this->name = x;
	}

	void set_year(int x)
	{
		this->year = x;
	}

	string get_name()
	{
		return name;
	}

	int get_year()
	{
		return year;
	}

	friend ostream& operator<<(ostream& os, People &other)
	{
		os << other.name << " " << other.year;
		return os;
	}
};

int main()
{
	ofstream outFile("test.txt");
	char arr[100];
	
	for (int i = 0; i < 4; i++)
	{
		cin.getline(arr, 100);
		outFile << arr << endl;
	}
	outFile.close();

	ifstream input("test.txt");
	string name;
	int year;

	vector<People> array1;
	People a("Pavel", 20);
	People b;
	People c;
	People d;
	array1.push_back(a);
	array1.push_back(b);
	array1.push_back(c);
	array1.push_back(d);

	int i = 0;
	while (input >> name >> year)
	{
		array1[i].set_name(name);
		array1[i].set_year(year);
		i++;
	}

	for (int i = 0; i < array1.size(); i++)
	{
		cout << array1[i] << endl;
	}
	
	cout << array1[1].get_name() << " " << array1[1].get_year() << endl;
}