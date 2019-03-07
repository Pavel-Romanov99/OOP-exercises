#include <iostream>
#include <string>
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

	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
};

class Circle
{
private:
	Point a;
	double r;
	string colour;
public:

	void set_point(Point b)
	{
		a = b;
	}

	void set_r(double new_r)
	{
		r = new_r;
	}

	void set_colour(string new_colour)
	{
		colour = new_colour;
	}

	Point get_point()
	{
		return a;
	}

	double get_r()
	{
		return r;
	}

	string get_colour()
	{
		return colour;
	}

	Circle()
	{
		a.set(0, 0);
		r = 0.0;
		colour = "shit";
	}

	Circle(Point new_a, double new_r, string new_colour)
	{
		a = new_a;
		r = new_r;
		colour = new_colour;
	}

	double perimeter()
	{
		return 2 * r*3.14;
	}

	double size()
	{
		return 3.14 * r * r;
	}
};

int main()
{
	Point a(1, 3);
	Circle circle(a, 3, "purple");
	cout << "Perimeter: " << circle.perimeter() << endl;
	cout << "Size: " << circle.size() << endl;
}
