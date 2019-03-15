#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int MAX = 20;
class BankAccount
{
private:
	string name;
	string id_number;
	double balance;
public:
	BankAccount()
	{
		name = "";
		id_number = "";
		balance = 0.0;
	}
	BankAccount(string new_name, string new_id, double new_balance)
	{
		name = new_name;
		id_number = new_id;
		balance = new_balance;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Id number: " << id_number << endl;
		cout << "Balance: " << balance << endl;
	} 
	void add_money(int x)
	{
		balance += x;
	}
	void take_money(int x)
	{
		balance -= x;
	}
};

class Factoriel
{
private:
	int a;
public:
	void set(int x)
	{
		a = x;
	}
	int fact()
	{
		int fact = 1;
		for (int i = 1; i <= a; i++)
		{
			fact = fact * i;
		}
		return fact;
	}
};

class Absolute
{
private:
	int a;
	double b;
public:
	void set_int(int x)
	{
		a = x;
	}
	void set_real(double y)
	{
		b = y;
	}
	int absolute_int()
	{
		return abs(a);
	}
	double absolute_real()
	{
		return abs(b);
	}
};

class Employee
{
	struct  {
		string first_name;
		string surname;
	}name;
	struct work {
		int hours;
		int salary;
	}work;
public:
	void read()
	{
		cout << "Name: "; cin >> name.first_name;
		cout << "Surname: "; cin >> name.surname;
		cout << "Working hours: "; cin >> work.hours;
		cout << "Salary: "; cin >> work.salary;
	}
	void print()
	{
		cout << name.first_name << " " << name.surname << endl; 
		cout << "Money: " << work.hours* work.salary << endl;
	}
};

const double GET_TO_RAD = 3.14 / 180;
class Angle
{
private:
	int angle;
public:
	void set_angle(int x)
	{
		angle = x;
	}
	double get_sin()
	{
		return sin(GET_TO_RAD * angle);
	}
	double get_cos()
	{
		return cos(GET_TO_RAD * angle);
	}
	double get_tan()
	{
		return tan(GET_TO_RAD * angle);
	}
};


class C
{
private:
	int a;
	int b;
public:
	void init(int x, int y)
	{
		a = x;
		b = y;
	}
	void display()
	{
		cout << a << " " << b << endl;
	}
};

class Point3
{
private:
	int x;
	int y;
	int z;
public:
	Point3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Point3(int new_x, int new_y, int new_z)
	{
		x = new_x;
		y = new_y;
		z = new_z;
	}

	Point3(const Point3& p)
	{
		x = p.x + 1;
		y = p.y + 2;
		z = p.z + 3;
	}

	int get_x()
	{
		return x;
	}

	int get_y()
	{
		return y;
	}

	int get_z()
	{
		return z;
	}

	void new_coordinates(int new_x, int new_y, int new_z)
	{
		x = new_x;
		y = new_y;
		z = new_z;
	}
	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

int main()
{
	Point3 point(1, 2, 3);
	point.print();
	point.new_coordinates(2, 3, 4);
	point.print();
	Point3 new_point;
	new_point.print();
	Point3 new_point1 = point;
	new_point1.print();

} 