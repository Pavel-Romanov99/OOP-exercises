#include <iostream>
using namespace std;

int const MAX = 100;
class Elf
{
private:
	char name[MAX];
	int age;
	int ability;
public:

	Elf()
	{
		age = 1;
		ability = 1;
		strcpy_s(name, "");
	}

	Elf(const char* new_name, int age_, int ability_)
	{
		strcpy_s(name, new_name);
		set_age(age_);
		set_ability(ability_);
	}

	Elf(const Elf &other)
	{
		strcpy_s(name, other.name);
		this->age = other.age;
		this->ability = other.ability;
	}

	void operator=(const Elf &other) 
	{
		strcpy_s(name, other.name);
		this->age = other.age;
		this->ability = other.ability;
	}

	int get_age()
	{
		return age;
	}

	int get_ability()
	{
		return ability;
	}

	const char* get_name() const
	{
		return name;
	}

	void set_age(int x)
	{
		if (x > 300 || x < 0)
		{
			this->age = 1;
		}
		else this->age = x;
	}

	void set_ability(int x)
	{
		if (x > 1 && x <= 15)
		{
			this->ability = x;
		}
		else this->ability = 1;
	}

	void set_name(const char* new_name)
	{
		strcpy_s(this->name, new_name);
	}

	bool operator==(const Elf& other)
	{
		if ((this->name == other.name) && (this->age == other.age) && (this->ability == other.ability))
		{
			return true;
		}
		 return false;
	}

	void printElf()
	{
		cout << this->get_name() << " " << this->get_age() << " " << this->get_ability() << endl;
	}

	friend ostream& operator<<(ostream& os, const Elf &other)
	{
		os << other.name << " " << other.age << " " << other.ability;
		return os;
	}
};


int const new_MAX = 50;
class ElfTeam
{
private:
	char team_name[new_MAX];
	Elf* elf_list;
	int size;
public:
	ElfTeam()
	{
		this->size = 0;
		strcpy_s(team_name, "");
		elf_list = new Elf[50];
	}

	ElfTeam(const char* new_name, int x)
	{
		this->size = 0;
		strcpy_s(team_name, new_name);
		if (x > 0 && x < 50)
		{
			elf_list = new Elf[x];
		}
		else elf_list = new Elf[50];
	}

	~ElfTeam()
	{
		delete[] elf_list;
 	}

	ElfTeam(const ElfTeam &other)
	{
		this->size = other.size;
		strcpy_s(team_name, other.team_name);
		elf_list = new Elf[other.size];
		memcpy(elf_list, other.elf_list, size);
	}

	void operator=(const ElfTeam &other)
	{
		this->size = other.size;
		strcpy_s(this->team_name, other.team_name);
		elf_list = new Elf[other.size];
		memcpy(elf_list, other.elf_list, size);
	}

	void AddElf(const Elf &other)
	{
		if (size < 50)
		{
			elf_list[++size] = other;
		}
		else cout << "List is full!" << endl;
	}

	double sum_age()
	{
		double sum = 0;
		for (int i = 1; i < size + 1; i++)
		{
			sum += elf_list[i].get_age();
		}
		return sum;
	}

	double sum_ability()
	{
		double sum = 0;
		for (int i = 1; i < size + 1; i++)
		{
			sum += elf_list[i].get_ability();
		}
		return sum;
	}

	double teamStrenght()
	{
		return this->sum_age() / this->sum_ability();
	}

	bool operator<( ElfTeam &other)
	{
		if (this->teamStrenght() < other.teamStrenght())
		{
			return true;
		}
		else return false;
	}

	
	bool contains(Elf &other)
	{
		bool contains = false;
		for (int i = 1; i < size + 1; i++)
		{
			if (elf_list[i] == other)
			{
				contains = true;
				break;
			}
		}
		return contains;
	}

	//doesn't work if there are two of the same elves
	void operator+=(const ElfTeam &other)
	{
		for (int i = 1; i < other.size + 1; i++)
		{
			if (this->contains(other.elf_list[i]) == false)
			{
				this->AddElf(other.elf_list[i]);
			}
		}
	}

	ElfTeam operator+(const ElfTeam &other)
	{
		ElfTeam temp;

		for (int i = 0; i < other.size; i++)
		{
			temp.AddElf(other.elf_list[i]);
		}
		return temp;
	}

	Elf strongest()
	{
		Elf temp;
		for (int i = 1; i < size + 1; i++)
		{
			if (elf_list[i].get_ability() > temp.get_ability())
			{
				temp = elf_list[i];
			}
		}
		return temp;
	}

	void printTeam()
	{
		for (int i = 1; i < size + 1; i++)
		{
			elf_list[i].printElf();
		}
	}
};

int main()
{
	Elf a("Ronaldo", 34, 2);
	Elf b("Perez", 34, 2);
	ElfTeam ab;
	ab.AddElf(a);
	ab.AddElf(b);


	Elf c("Messi", 255, 12);
	Elf d("Perez", 34, 2);
	ElfTeam cd;
	cd.AddElf(c);
	cd.AddElf(d);
	
	ElfTeam temp("barcelona", 10);
	ab += cd;
	ab.printTeam();
}