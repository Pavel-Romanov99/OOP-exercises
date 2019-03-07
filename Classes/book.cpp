#include <iostream>
#include <string>
#include <vector>
using namespace std;

int const MAX = 100;

class Book
{
private:
	string name;
	vector <int> pages;
public:
	int vector_size()
	{
		return pages.size();
	}

	void set_name(string new_name)
	{
		name = new_name;
	}
	string get_name()
	{
		return name;
	}
	void set_pages(vector <int> new_pages)
	{
		pages = new_pages;
	}
	const vector<int>& get_pages() const 
	{ 
		return this->pages; 
	}
	Book()
	{
		name = "";
		pages.resize(0);
	}
	Book(string new_name, vector <int> new_pages)
	{
		name = new_name;
		pages = new_pages;
	}
	void add_page(int x)
	{
		pages.insert(pages.end(), x);
	}
	void remove_page(int x)
	{
		pages.erase(pages.begin() + x);
	}
};

int main()
{
	Book a;
	a.set_pages({ 1,2,3,4,5 });
	a.add_page(100);
	a.add_page(200);
	a.remove_page(3);

	for (int i = 0; i < a.vector_size(); i++)
	{
		cout << a.get_pages()[i]<< " ";
	}
	cout << endl;
}