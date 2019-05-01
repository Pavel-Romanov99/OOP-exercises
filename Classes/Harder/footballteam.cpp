#include <iostream>
#include <cstring>
using namespace std;

int const MAX = 100;
class Footballer
{
private:
	char name[MAX];
	int age;
	int height;
public:
	Footballer()
	{
		age = 0;
		height = 0;
		strncpy_s(this->name, "", MAX - 1);
	}

	Footballer(char const* new_name, int age, int height)
	{
		strncpy_s(this->name, new_name, MAX - 1);
		this->age = age;
		this->height = height;
	}

	const char* get_name()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	int getHeight()
	{
		return height;
	}

	void readPlayer()
	{
		char name_[MAX];
		cin >> name_;
		int age_;
		cin >> age_;
		int height_;
		cin >> height_;

		strncpy_s(this->name, name_, MAX - 1);
		this->age = age_;
		this->height = height_;
	}

	Footballer operator>(Footballer const &a)
	{
		if (a.age > age)
		{
			return a;
		}
		return *this;
	}

	void Print()
	{
		cout << name << " " << age << " " << height << endl;
	} 
};

class Team
{
private:
	char team_name[MAX];
	Footballer *squad;
	int size;
	int capacity;
public:
	Team()
	{
		size = 0;
		capacity = 0;
		strcpy_s(team_name, "");
		squad = new Footballer[capacity];
	}

	Team(int num, char const* new_name)
	{
		size = 0;
		capacity = num;
		strcpy_s(team_name, new_name);
		squad = new Footballer[capacity];
	}

	Team(const Team& other)
		: size(other.size)
	{
		capacity = other.capacity;
		this->squad = new Footballer[capacity];
		
		for (int i = 1; i < size + 1; i++)
		{
			squad[i] = other.squad[i];
		}
	}

	~Team()
	{
		delete[] squad;
	}
	 
	void addPlayer(const Footballer &other)
	{
		if (capacity > size)
		{
			squad[++size] = other;
		}
		else cout << "Team is full! " << endl;
	}

	Footballer tallestPlayer()
	{
		Footballer a;
		for (int i = 1; i < size + 1; i++)
		{
			if (a.getHeight() < squad[i].getHeight())
			{
				a = squad[i];
			}
		}
		return a;
	}

	void PrintTeam()
	{
		for (int i = 1; i < size + 1; i++)
		{
			squad[i].Print();
		}
	}
};

int main()
{
	Footballer a("Messi", 31, 170);
	Footballer b("Ronaldo", 34, 185);
	Footballer c("Pirlo", 40, 190);
	Footballer d("Pavel", 19, 178);
	
	Team Allstar(5, "Barcelona");
	Allstar.addPlayer(a);
	Allstar.addPlayer(b);
	
	Team ab = Allstar;
	ab.addPlayer(c);
	Allstar.addPlayer(d);
	
	Allstar.PrintTeam();
	cout << endl;
	ab.PrintTeam();
 }