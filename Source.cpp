#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX = 100;
class Rule
{
private:
	char rule[MAX];
public:

	//default constructor
	Rule()
	{
		strcpy_s(rule, "");
	}

	//constructor
	Rule(const char* other)
	{
		strcpy_s(rule, other);
	}

	//operator << for rules
	friend ostream& operator<<(ostream& os, Rule &other)
	{
		os << other.rule;
		return os;
	}

	// operator == 
	bool operator==(const Rule &other)
	{
		bool check = true;

		for (int i = 0; i < strlen(this->rule); i++)
		{
			if (rule[i] != other.rule[i])
			{
				check = false;
				break;
			}
		}
		return check;
	}
};

class Variables
{
private:
	char name;
	vector <Rule> rules;

public:

	//default constructor
	Variables()
	{
		this->name = 'S';
	}
	
	//constructor
	Variables(char var)
	{
		if (var >= 65 && var <= 90)
		{
			this->name = var;
		}
	}

	//getter
	char getName()
	{
		return name;
	}

	//adding a rule
	void addRule(const Rule &other)
	{
		rules.push_back(other);
	}

	//finding the position in the array
	int Position_(const Rule &other)
	{
		int counter = 0;

		for (int i = 0; i < rules.size(); i++)
		{
			if (rules[i] == other)
			{
				return counter;
			}
			counter++;
		}
	}

	//removing a rule
	void removeRule(const Rule &other)
	{
		int n = Position_(other);
		rules.erase(rules.begin() + n);
	}

	//print variable rules
	void PrintRules()
	{
		cout << this->name << " -> ";
		for (int i = 0; i < rules.size(); i++)
		{
			cout << rules[i] << " | ";
		}
		// cout << rules[size];
		cout << endl;
	}

	// operator << for variables
	friend ostream& operator<<(ostream &os, Variables &other)
	{
		os << other.getName() << " -> ";
		for (int i = 0; i < other.rules.size(); i++)
		{
			os << other.rules[i] << " | ";
		}
		os << endl;
		return os;
	}
};

//--------------------------------------------------------------------

class CFG
{
private:
	string name;
	Variables *variables;
	int size;
	int capacity;

	//Start variable
	Variables start;
public:

	//default constructor
	CFG()
	{
		name = "G";
		capacity = 10;
		variables = new Variables[capacity];
		variables[++size] = this->start;
	}

	//constructor
	CFG(string name, int capacity, Variables new_start)
	{
		this->name = name;
		this->capacity = capacity;
		this->start = new_start;
		variables = new Variables[capacity];
		variables[++size] = new_start;
	}

	//destructor
	~CFG()
	{
		delete[] variables;
	}

	//Adding a variable to the grammar
	void addVariable(const Variables &other)
	{
		if (size < capacity)
		{
			variables[++size] = other;
		}
		else cout << "Full!" << endl;
	}

	//Printing the grammar
	void PrintGrammar()
	{
		for (int i = 1; i < this->size + 1; i++)
		{
			variables[i].PrintRules();
		}
	}

	//Write to file
	void Write()
	{
		ofstream myfile;
		myfile.open("CFG.txt");
		
		for (int i = 1; i < this->size + 1; i++)
		{
			myfile << variables[i] << endl;
		}
	}

	//Union of grammars
	CFG Unify(const CFG &G1, const CFG &G2)
	{

	}

	//Concatenation of grammars
	CFG Concatenate(const CFG &G1, const CFG &G2)
	{

	}
};

int main()
{
	Variables S;
	Rule rule("1S1");
	Rule a("LOL");
	Rule b("HEY");

	S.addRule(rule);
	S.addRule(a);
	S.addRule(b);

	Variables A('A');
	Rule e("101");
	Rule f("0");

	A.addRule(e);
	A.addRule(f);

	Variables C('C');
	Rule c("121");
	Rule d("15");

	C.addRule(c);
	C.addRule(d);

	Variables H;

	CFG grammar("G", 10, H);
	grammar.addVariable(S);
	grammar.addVariable(A);
	grammar.addVariable(C);
	grammar.PrintGrammar();
	grammar.Write();
}