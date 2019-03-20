#include <iostream>
using namespace std;

class Point3
{
private:
	int x, y, z;
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
	void set_x(int new_x)
	{
		x = new_x;
	}
	void set_y(int new_y)
	{
		y = new_y;
	}
	void set_z(int new_z)
	{
		z = new_z;
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

	void read(int n, Point3 a[])
	{
		for (int i = 0; i < n; i++)
		{
			int p;
			cout << "X = "; cin >> p;
			a[i].set_x(p);
			cout << "Y = "; cin >> p;
			a[i].set_y(p);
			cout << "Z = "; cin >> p;
			a[i].set_z(p);
		}
	}

	void symetric(int n, Point3 a[])
	{
		for (int i = 0; i < n; i++)
		{
			a[i].set_x(-a[i].get_x());
			a[i].set_y(-a[i].get_y());
			a[i].set_z(-a[i].get_z());
		}
	}

	void print(int n, Point3 a[])
	{
		for (int i = 0; i < n; i++)
		{
			cout << "X = " << a[i].get_x() << " "; 
			cout << "Y = " << a[i].get_y() << " ";
			cout << "Z = " << a[i].get_z() << " ";
		}
		cout << endl;
	}
};


int main()
{
	Point3 a[3];
	int n = 3;

	a->read(n, a);
	a->print(n, a);
	a[1].symetric(n, a);
	a->print(n, a);
}