#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	void set(int new_x, int new_y)
	{
		x = new_x;
		y = new_y;
	}

	int get_x()
	{
		return x;
	}

	int get_y()
	{
		return y;
	}

	void change_x(int a)
	{
		x += a;
	}

	void change_y(int b)
	{
		y += b;
	}
};


int main()
{
	Point a;
	a.set(1, 3);
	cout << a.get_x() << " " <<  a.get_y() << endl;

	a.change_x(2);
	a.change_y(3);
	cout << a.get_x() << " " << a.get_y() << endl;

	
}
