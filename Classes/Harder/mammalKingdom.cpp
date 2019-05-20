#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Food
{
public:
	string name;

	Food(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return this->name;
	}
};

class Mammal
{
public:
	int age;
	int legs;
	bool fur;

	virtual string getName() const {
		return "Name: ";
	}

	virtual bool eats(Food food) const {
		return true;
	}

	virtual string furColor() const {
		return "No colour:" ;
	}

	virtual bool isSameSpeciesLike(Mammal* otherMammal) {
		return true;
	}
};

class Hippo : public Mammal
{
public:
	Hippo()
	{
		age = 5;
		legs = 4;
		fur = true;
	}

	string getName() const
	{
		return "Hippo";
	}

	bool eats(Food &food)
	{
		if (food.name == "grass")
		{
			return true;
		}
		return false;
	}

	string furColor()
	{
		if (fur)
		{
			return "Purple";
		}
		return "Hippos have fur man";
	}

	bool isSameSpeciesLike(Mammal* otherMammal) 
	{
		if (typeid(*this) == typeid(*otherMammal))
		{
			return true;
		}
		return false;
	}
};

class Human : public Mammal
{
public:
	Human()
	{
		age = 45;
		legs = 2;
		fur = false;
	}

	string getName() const
	{
		return "Larry";
	}

	bool eats(Food &food)
	{
		if (food.name == "meat")
		{
			return true;
		}
		return false;
	}

	string furColor()
	{
		if (fur)
		{
			return "Purple";
		}
		return "No fur sir";
	}

	bool isSameSpeciesLike(Mammal* otherMammal)
	{
		if (typeid(*this) == typeid(*otherMammal))
		{
			return true;
		}
		return false;
	}
};


int main()
{
	Human a;
	Human b;
	Hippo c;

	Mammal *p = &c;
	Mammal *ptr = &b;
	cout << p->getName() << endl;
	cout << c.getName() << endl;

	Food food("meat");

	if (ptr->eats(food.getName()))
	{
		cout << "I love meat" << endl;
	}
	else cout << "I hate meat!" << endl;

	if (a.isSameSpeciesLike(p))
	{
		cout << "Same" << endl;
	}
	else	cout << "Diffrent" << endl;
}