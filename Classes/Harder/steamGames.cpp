#include <iostream>
#include <cstring>
using namespace std;

int const Max = 100;
class Games {
private:
	char title[Max];
	char company[Max];
	double grade;
public:
	Games()
	{
		strcpy_s(title, "");
		strcpy_s(company, "");
		grade = 0;
	}
	
	Games(char const* new_title, char const* new_company, double new_grade)
	{
		strncpy_s(this->title, new_title, Max - 1);
		this->title[Max - 1] = '/0';
		strncpy_s(this->company, new_company, Max - 1);
		this->company[Max - 1] = '/0';
		grade = new_grade;
	}

	char const*  getTitle()
	{
		return title;
	}

	char const* getCompany()
	{
		return company;
	}

	double getGrade()
	{
		return grade;
	}
};

class Steam
{
private:
	Games* library;
	int capacity;
	int size;

	void copy(Steam const &other)
	{
		capacity = other.capacity;
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			library[i] = other.library[i];
		}
	}
public:
	Steam(int num)
	{
		size = 0;
		capacity = num;
		library = new Games[capacity];
	}

	Steam()
	{
		size = 0;
		capacity = 50;
		library = new Games[capacity];
	}

	~Steam()
	{
		delete[] library;
	}

	Steam(Steam const& other) {
		copy(other);
	}

	void addGame(Games const &game)
	{
		if (size < capacity) 
		{
			library[++size] = game;
		}
		else cout << "Library is full!" << endl;
	}

	void bestRated()
	{
		Games test;
		for (int i = 1; i < size + 1; i++)
		{
			if (test.getGrade() < library[i].getGrade())
			{
				test = library[i];
			}
		}
		cout << test.getTitle() << " is the best rated game!" << endl;
	}

	double averageRatings()
	{
		double sum = 0.0;
		for (int i = 1; i < size + 1; i++)
		{
			sum += library[i].getGrade();
		}
		return sum / size;
	}
};

int main()
{
	Games game1("GTA V", "Rockstar", 9.0);
	Games game2("Witcher 3", "CD Project red", 10.0);
	Games game3("GTA SA", "Rockstar", 8.5);
	Games game4("FIFA 19", "EA", 6.0);
	Games game5("Prince of Persia", "Ubisoft", 11.0);
	Steam library;
	library.addGame(game1);
	library.addGame(game2);
	library.addGame(game3);
	library.addGame(game4);
	library.addGame(game5);
	library.bestRated();
	cout << library.averageRatings() << endl; 
}
