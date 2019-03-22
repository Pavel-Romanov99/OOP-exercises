#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

class Date
{
private:
	int day, month, year;
public:

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	int get_day()
	{
		return day;
	}

	int get_month()
	{
		return month;
	}

	int get_year()
	{
		return year;
	}

	void set_day(int x)
	{
		day = x;
	}

	void set_month(int x)
	{
		month = x;
	}

	void set_year(int x)
	{
		year = x;
	}

	void print()
	{
		cout << day << "." << month << "." << year << endl;
	}
};

class Patient
{
private:
	string name;
	Date DOB;
	int visits;
public:

	Patient()
	{
		visits = 0;
	}

	Patient(string name, Date DOB, int visits)
	{
		this->name = name;
		this->DOB = DOB;
		this->visits = visits;
	}

	string get_name()
	{
		return name;
	}

	Date get_DOB()
	{
		return DOB;
	}

	int get_visits()
	{
		return visits;
	}

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Date: "; DOB.print();
		cout << "Visits: " << visits << endl;
	}
};

class Doctor
{
private:
	string name;
	Patient patients[MAX];
	int patient_registered;
public:
	Doctor()
	{
		name = "";
		patient_registered = 0;
	}

	string get_name()
	{
		return name;
	}

	void register_patient(const Patient& P)
	{
		patients[patient_registered] = P;
		patient_registered++;
	}

	double average()
	{
		int total_visits;
		for (int i = 0; i < patient_registered; i++)
		{
			total_visits += patients[i].get_visits();
		}
		return total_visits / patient_registered;
	}

	void print_upper(int limit)
	{
		for (int i = 0; i < patient_registered; i++)
		{
			if (patients[i].get_visits() > limit)
			{
				patients[i].print();
			}
		}
	}
};

int main()
{

}