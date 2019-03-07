#include <iostream>
using namespace std;

class Time
{
private:
	int h;
	int m;
	int s;
public:
	void set_h(int new_h)
	{
		h = new_h;
	}
	void set_m(int new_m)
	{
		m = new_m;
	}
	void set_s(int new_s)
	{
		s = new_s;
	}
	int get_h()
	{
		return h;
	}
	int get_m()
	{
		return m;
	}
	int get_s()
	{
		return s;
	}
	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int new_h, int new_m, int new_s)
	{
		if (new_h > 0 && new_h < 60)
		{
			h = new_h;
		}
		if (new_m > 0 && new_m < 60)
		{
			m = new_m;
		}
		if (new_s > 0 && new_s < 60)
		{
			s = new_s;
		}
	}
	void print()
	{
		cout << h << ":" << m << ":" << s << endl;
	}
	
};

void compare(Time a, Time b)
{
	if (a.get_h() > b.get_h())
	{
		a.print();
	}
	else if (a.get_h() < b.get_h())
	{
		b.print();
	}

	else if (a.get_h() == b.get_h())
	{
		if (a.get_m() > b.get_m())
		{
			a.print();
		}
		else b.print();
	}

	else if ((a.get_h() == b.get_h()) && (a.get_m() == b.get_m()))
	{
		if (a.get_s() > b.get_s())
		{
			a.print();
		}
		else b.print();
	}

} 

int main()
{
	Time a(23, 23, 53);
	Time b(23, 23, 52);
	compare(a, b);
}