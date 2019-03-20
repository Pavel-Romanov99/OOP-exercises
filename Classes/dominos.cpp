#include <iostream>
#include <string>
using namespace std;

class Adress
{
private:
	string city, street;
	int building, apartment;
public:
	Adress()
	{
		city = "";
		street = "";
		building = 0;
		apartment = 0;
	}
	Adress(string city, string street, int building, int apartment)
	{
		this->city = city;
		this->street = street;
		this->building = building;
		this->apartment = apartment;
	}

	string get_city()
	{
		return city;
	}

	string get_street()
	{
		return street;
	}

	int get_building()
	{
		return building;
	}

	int get_apartment()
	{
		return apartment;
	}

	void print()
	{
		cout <<"Adress: " << "city code: " << city << " street: " << street
			<< " building: " << building << " apartment: " << apartment << endl;
	}
};

class Customer
{
private:
	Adress adress;
	string name;
	string email;
	string number;
public:
	Customer()
	{
		name = "";
		email = "";
		number = "";
	}
	Customer(Adress adress, string name, string email, string number)
	{
		this->adress = adress;
		this->name = name;
		this->email = email;
		this->number = number;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		adress.print();
		cout << "Email: " << email << endl;
		cout << "Number: " << number << endl;
	}
};

class Item
{
private:
	string code;
	int quantity;
public:
	Item()
	{
		code = "";
		quantity = 0;
	}
	Item(string code, int quantity)
	{
		this->code = code;
		this->quantity = quantity;
	}
	string get_code()
	{
		return code;
	}
	int get_quantity()
	{
		return quantity;
	}
	void print()
	{
		cout << code << endl;
		cout << "quantity: " << quantity << endl;
	}
};

class Order
{
private:
	Customer customer;
	Item item;
public:
	Order()
	{

	}

	Order(Customer customer, Item item)
	{
		this->customer = customer;
		this->item = item;
	}

	void final_order(Customer customer, Item item)
	{
		cout << "Customer details: " << endl; 
		customer.print();
		cout << "Has ordered product number " << item.get_code() << " " << item.get_quantity() << " times." << endl;
	}

	//Dublicate order()
	//Add order()
};

int main()
{
	Adress a("2800", "Lozenka", 44, 5);
	Customer gosho(a, "Gosho", "pavel.romanov@gmial.com", "0879555512");
	Item item("23", 3);
	Order b;
	b.final_order(gosho, item);
}