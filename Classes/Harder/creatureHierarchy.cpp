#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX = 100;
class Creature
{
public:
	char name[MAX];
	int hp;
	int attack;
	int defence;

	Creature()
	{
		strcpy_s(name, "Random name");
		this->hp = 0;
		this->attack = 0;
		this->defence = 0;
	}

	Creature(const char* name, int hp, int attack, int defence)
	{
		strcpy_s(this->name, name);
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;
	}

	Creature(const Creature& other)
	{
		strcpy_s(this->name, other.name);
		this->hp = other.hp;
		this->attack = other.attack;
		this->defence = other.defence;
	}

	void operator=(const Creature &other)
	{
		strcpy_s(this->name, other.name);
		this->hp = other.hp;
		this->attack = other.attack;
		this->defence = other.defence;
	}

	friend ostream& operator<<(ostream &os, Creature &other)
	{
		os << other.name << " " << other.hp << " " << other.attack << " " << other.defence;
		return os;
	}

	bool operator<(const Creature &other)
	{
		if (this->attack > other.attack)
		{
			return true;
		}
		return false;
	}

	void setName(const char* name)
	{
		strcpy_s(this->name, name);
	}
};

class Orc : public Creature
{
private:
	int strenght;
public:
	Orc()
	{
		strcpy_s(this->name, "Sauron");
		strenght = 0;
	}

	Orc(const char* name, int hp, int attack, int defence, int strenght)
	{
		strcpy_s(this->name, name);
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;

		this->strenght = strenght;
		this->attack += strenght;
		this->hp += strenght;
	}
};

class Elf : public Creature
{
public:
	void setStats(int x, int y)
	{
		this->attack += x;
		this->defence += y;
	}
};

int main()
{
	Orc pavel("Pavel", 100, 500, 100, 50);
	Elf miro;

	Orc blago;
	cout << blago << endl;

	if (miro < pavel)
	{
		cout << "Miro a greater warrior!" << endl;
	}
	else cout << "Who are you kidding! " << endl;

	Elf eva;
	eva = miro;
	eva.setName("Eva");
	cout << eva << endl;
}