#include <iostream>
using namespace std;

struct rat
{
	int numer;
	int denom;

	rat()
	{
		numer = 0;
		denom = 1;
	}

	rat(int x, int y)
	{
		numer = x;
		denom = y;
	}

	void read()
	{
		cout << "numer: ";
		cin >> numer;

		do
		{
			cout << "denom: ";
			cin >> denom;
		} while (denom == 0);
	}

	int get_numer() const
	{
		return numer;
	}

	int get_denom() const
	{
		return denom;
	}

	void print() const
	{
		cout << numer << "/" << denom << endl;
	}
};

rat sum(rat a, rat b)
{
	rat r(a.numer * b.denom + b.numer* a.denom, a.denom* b.denom);
	return r;
}

rat sub(rat a, rat b)
{
	rat r(a.numer * b.denom - b.numer* a.denom, a.denom* b.denom);
	return r;
}

rat multi(rat a, rat b)
{
	rat r(a.numer *b.numer, a.denom* b.denom);
	return r;
}

rat div(rat a, rat b)
{
	rat r(a.numer * b.denom, a.denom * b.numer);
	return r;
}

int main()
{
	return 0;
}
