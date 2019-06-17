#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
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

	//setter
	void set_rule(const char* a)
	{
		for (int i = 0; i < MAX; i++)
		{
			rule[i] = a[i];
		}
	}
};

class Variables
{
private:
	string name;
	vector <Rule> rules;

public:

	//default constructor
	Variables()
	{
		this->name = "S";
	}
	
	//constructor
	Variables(string var)
	{
		this->name = var;
	}

	//getter
	string getName()
	{
		return name;
	}

	//set name
	void set_name(string name)
	{
		this->name = name;
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
		return -1;
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
		capacity = 30;
		size = 0;
		variables = new Variables[capacity];
		variables[++size] = this->start;
	}

	//constructor
	CFG(string name, int capacity, Variables new_start)
	{
		this->name = name;
		this->capacity = capacity;
		this->size = 0;
		this->start = new_start;
		variables = new Variables[capacity];
		variables[++size] = new_start;
	}

	//copy constructor
	CFG(const CFG &other)
	{
		capacity = capacity + other.capacity;
		Variables *oldVariables = other.variables;
		variables = new Variables[other.capacity];
		int oldSize = other.size;

		for (int i = 0; i < oldSize; i++)
		{
			this->addVariable(oldVariables[i]);
		}

	}

	//destructor
	~CFG()
	{
		delete[] variables;
	}

	//Adding a variable to the grammar
	void addVariable(const Variables &other)
	{
		if (size < capacity - 1)
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

	//get starting variable
	Variables get_start()
	{
		return this->start;
	}

	string get_name()
	{
		return this->name;
	}

	//Union of grammars
	void Unify( CFG &G1,  CFG &other)
	{
		other.capacity = G1.capacity + this->capacity;
		Variables *oldVariables = this->variables;
		other.variables = new Variables[other.capacity];
		int oldSize = other.size;
		other.size = 0;

		for (int i = 1; i < this->size + 1; i++)
		{
			other.addVariable(oldVariables[i]);
		}

		for (int i = 1; i < G1.size + 1; i++)
		{
			other.addVariable(G1.variables[i]);
		}
		
		string str1 = G1.start.getName();
		string str2 = this->start.getName();

		char tab1[1024];
		strcpy_s(tab1, str1.c_str());

		char tab2[1024];
		strcpy_s(tab2, str2.c_str());

		Rule rule1(tab1);
		Rule rule2(tab2);

		other.start.addRule(rule1);
		other.start.addRule(rule2);
		other.addVariable(other.start);
	}

	//Concatenation of grammars
	void Concatenate( CFG &G1, CFG &other)
	{
		other.capacity = G1.capacity + this->capacity;
		Variables *oldVariables = this->variables;
		other.variables = new Variables[other.capacity];
		int oldSize = other.size;
		other.size = 0;

		for (int i = 1; i < this->size + 1; i++)
		{
			other.addVariable(oldVariables[i]);
		}

		for (int i = 1; i < G1.size + 1; i++)
		{
			other.addVariable(G1.variables[i]);
		}

		string str1 = G1.start.getName();
		string str2 = this->start.getName();
		string str = str1 + str2;

		char tab1[1024];
		strcpy_s(tab1, str.c_str());

		Rule rule1(tab1);

		other.start.addRule(rule1);
		other.addVariable(other.start);
	}

	//Klenee star
	void Klenee_star( CFG &other)
	{
		Variables *oldVariables = this->variables;
		other.variables = new Variables[other.capacity];
		int oldSize = other.size;
		other.size = 0;

		for (int i = 1; i < this->size + 1; i++)
		{
			other.addVariable(oldVariables[i]);
		}

		string str1 = "epsilon";
		string str2 = this->start.getName();
		string str = str2 + other.start.getName();


		char tab1[1024];
		strcpy_s(tab1, str1.c_str());

		char tab2[1024];
		strcpy_s(tab2, str.c_str());

		Rule rule1(tab1);
		Rule rule2(tab2);

		other.start.addRule(rule1);
		other.start.addRule(rule2);
		other.addVariable(other.start);
	}
};


int main()
{
	// --------- first grammar ---------------
	Variables S("S");
	Rule a("LOL");
	Rule b("HEY");
	S.addRule(a);
	S.addRule(b);

	Variables A("A");
	Rule e("101");
	Rule f("0");
	A.addRule(e);
	A.addRule(f);

	CFG grammar1("G1", 20, S);
	grammar1.addVariable(A);



	// -------- second grammar -----------------
	Variables C("C");
	Rule c("1D1");
	Rule d("15");
	C.addRule(c);
	C.addRule(d);

	Variables D("D");
	Rule p("13");
	Rule u("11");
	D.addRule(p);
	D.addRule(u);

	CFG grammar2("G2", 20, C);
	grammar2.addVariable(D);

	// --------- third grammar -----------------
	Variables Y("Y");
	CFG grammar3("G3", 20, Y);

	vector<CFG> grammars;
	grammars.push_back(grammar1);
	grammars.push_back(grammar2);
	grammars.push_back(grammar3);

	string command;

	while (true)
	{
		cin >> command;

		//Write command
		if (command == "write")
		{
			string argument1;
			cin >> argument1;

			int counter = 0;
			for (int i = 0; i < 3; i++)
			{
				if (argument1 == grammars[i].get_name())
				{
					break;
				}
				counter++;
			}
			int index = counter;
			grammars[index].Write();
		}

		//Print command
		if (command == "print")
		{
			string argument;
			cin >> argument;

			int counter = 0;
			for (int i = 0; i < 3; i++)
			{
				if (argument == grammars[i].get_name())
				{
					break;
				}
				counter++;
			}
			int index = counter;
			grammars[index].PrintGrammar();
		}

		//exit command
		if (command == "exit")
		{
			cout << "Program is done!" << endl;
			return 0;
		}
	}
	
}
