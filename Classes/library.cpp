#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library
{
private:
	vector <string> books;
public:
	Library()
	{
		books.resize(0);
	}

	Library(vector <string> new_books)
	{
		books = new_books;
	}

	void set_books(vector <string> new_books)
	{
		books = new_books;
	}

	const vector<string>& get_books() const
	{
		return this->books;
	}
	
	void add_books(string book)
	{
		books.insert(books.end(), book);
	}

	void delete_books(int x)
	{
		books.erase(books.begin() + x);
	}

	int library_size()
	{
		return books.size();
	}
};

int main()
{
	Library classics({ "LOL", "LMFAO", "More" });
	classics.add_books("Emil ot lioneberiq");
	classics.delete_books(0);

	for (int i = 0; i < classics.library_size(); i++)
	{
		cout << classics.get_books()[i] << " ";
	}
}