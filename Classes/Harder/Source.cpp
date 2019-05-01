#include <iostream>
#include <algorithm>
using namespace std;

int const MAX = 100;
class Set
{
private:
	int *set;
	int capacity;
	int size;

public:
	Set()
	{
		size = 0;
		capacity = 0;
		set = new int[capacity];
	}

	Set(int n)
	{
		size = 0;
		capacity = n;
		set = new int[capacity];
	}

	bool contains(int x) const
	{
		bool contains = false;
		for (int i = 1; i < size + 1; i++)
		{
			if (set[i] == x)
			{
				contains = true;
				break;
			}
		}
		return contains;
	}

	bool insert(int x)
	{
		if (contains(x) == true)
		{
			return false;
		}
		else
		{
			if (size < capacity)
			{
				set[++size] = x;
				return true;
			}
		}
	}

	bool equals(const Set &other) const
	{
		if (size != other.size)
		{
			return false;
		}

		for (int i = 1; i < size + 1; i++)
		{
			if (!other.contains(set[i]))
			{
				return false;
			}
		}
		return true;
	}

	void unifyWith(const Set &other)
	{
		for (int i = 1; i < other.size + 1; i++)
		{
			if (!this->contains(other.set[i]))
			{
				set[++size] = other.set[i];
			}
		}
	}

	void intersectWith(const Set &other)
	{
		Set temp(size);
		for (int i = 1; i < other.size + 1; i++)
		{
			if (this->contains(other.set[i]))
			{
				temp.insert(set[i]);
			}
		}
		size = temp.size;
		set = temp.set;
	}

	void print()
	{
		
		for (int i = 1; i < size + 1; i++)
		{
			cout << set[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Set a(10);
	a.insert(1);
	a.insert(2);
	a.insert(3);
	Set b(10);
	b.insert(1);
	b.insert(2);
	b.insert(33);

	a.intersectWith(b);
	a.print();
	a.unifyWith(b);
	a.print();
}
