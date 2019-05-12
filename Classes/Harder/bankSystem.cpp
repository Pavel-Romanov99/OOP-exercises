#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BankAccount
{
private:
	string id;
	string name;
	double balance;
public:
	BankAccount()
	{
		this->id = "";
		this->name = "";
		this->balance = 0.0;
	}

	BankAccount(string id, string name, double balance)
	{
		this->id = id;
		this->name = name;
		this->balance = balance;
	}

	bool operator==(const BankAccount &other)
	{
		if (id == other.id && name == other.name && balance == other.balance)
		{
			return true;
		}
		return false;
	}

	string get_name()
	{
		return name;
	}

	string get_id()
	{
		return id;
	}

	double get_balance()
	{
		return balance;
	}

	friend ostream& operator<<(ostream &os, const BankAccount &other)
	{
		os << other.name << " " << other.id << " " << other.balance;
		return os;
	}
};

class StaffMember
{
private:
	string staff_id;
	string name;
	int age;

public:
	double salary;
	StaffMember()
	{
		this->staff_id = "";
		this->name = "";
		this->age = age;
		this->salary = salary;
	}

	friend ostream& operator<<(ostream &os, const StaffMember &other)
	{
		os << other.name << " " << other.staff_id << " " << other.age << " " << other.salary;
		return os;
	}

	StaffMember(string staff_id, string name, int age, double salary)
	{
		this->staff_id = staff_id;
		this->name = name;
		this->age = age;
		this->salary = salary;
	}

	bool operator==(const StaffMember &other)
	{
		if (staff_id == other.staff_id && name == other.name && age == other.age)
		{
			return true;
		}
		return false;
	}

	string get_staffID()
	{
		return staff_id;
	}

	string get_name()
	{
		return name;
	}

	int get_age()
	{
		return age;
	}

	double get_salary()
	{
		return salary;
	}

	void setSalary(double x)
	{
		this->salary = x;
	}
};

class BankSystem
{
private:
	BankAccount * account_list;
	StaffMember * staff_list;
	int account_size;
	int staff_size;
public:
	BankSystem()
	{
		account_size = 0;
		staff_size = 0;
		account_list = new BankAccount[50];
		staff_list = new StaffMember[50];
	}

	~BankSystem()
	{
		delete[] account_list;
		delete[] staff_list;
	}

	void addAccount(const BankAccount &other)
	{
		if (account_size < 50)
		{
			account_list[++account_size] = other;
		}
		else cout << "Account list is full!" << endl;
	}

	void addStaff(const StaffMember &other)
	{
		if (staff_size < 50)
		{
			staff_list[++staff_size] = other;
		}
		else cout << "Staff list is full!" << endl;
	}

	int Position(const BankAccount &other)
	{
		int counter = 0;

		for (int i = 0; i < account_size + 1; i++)
		{
			if (account_list[i] == other)
			{
				return counter;
			}
			counter++;
		}
	}

	void deleteAccount(const BankAccount &other)
	{
		int position = Position(other);

		for (int i = position; i < account_size + 1; i++)
		{
			BankAccount temp = account_list[i];
			account_list[i] = account_list[i + 1];
			account_list[i + 1] = temp;
		}
	}

	int Position_(const StaffMember &other)
	{
		int counter = 0;

		for (int i = 0; i < staff_size + 1; i++)
		{
			if (staff_list[i] == other)
			{
				return counter;
			}
			counter++;
		}
	}

	void deleteStaff(const StaffMember &other)
	{
		int position = Position_(other);

		for (int i = position; i < staff_size + 1; i++)
		{
			StaffMember temp = staff_list[i];
			staff_list[i] = staff_list[i + 1];
			staff_list[i + 1] = temp;
		}
	}

	double totalDeposit()
	{
		double sum = 0;
		for (int i = 0; i < account_size + 1; i++)
		{
			sum += account_list[i].get_balance();
		}
		return sum;
	}

	double annualSalary()
	{
		double total = 0;
		for (int i = 0; i < staff_size ; i++)
		{
			total += staff_list[i].get_salary();
		}
		return total;
	}

	void setAllSalaries(double x)
	{
		for (int i = 0; i < staff_size + 1; i++)
		{
			staff_list[i].salary = x;
		}
	}

	void Write()
	{
		ofstream myfile;
		myfile.open("example.txt");

		myfile << "Bank Accounts" << endl;
		myfile << "--------------------------------" << endl;
		for (int i = 1; i < account_size + 1; i++)
		{
			myfile << account_list[i] << endl;
		}
		myfile << endl;
		myfile << "Staff Members" << endl;
		myfile << "--------------------------------" << endl;
		for (int i = 1; i < staff_size + 1; i++)
		{
			myfile << staff_list[i] << endl;
		}
		myfile.close();
		cout << "Writing successfull!" << endl;
	}
};

int main()
{
	BankAccount a("120", "Pavel", 500);
	BankAccount b("240", "Miro", 12);
	BankAccount c("120", "Pavel", 500);
	BankAccount e("240", "Miro", 12);
	BankAccount f("120", "Pavel", 500);
	BankAccount g("240", "Miro", 12);
	BankAccount h("120", "Pavel", 500);
	BankAccount i("240", "Miro", 12);


	StaffMember jc("121", "Simona", 20, 1500);
	StaffMember kd("122", "Eva", 19, 600);

	
	BankSystem bnb;
	bnb.addAccount(a);
	bnb.addAccount(b);
	bnb.addAccount(c);
	bnb.addAccount(e);
	bnb.addAccount(f);
	bnb.addAccount(g);
	bnb.addAccount(h);

	bnb.addStaff(jc);
	bnb.addStaff(kd);

	bnb.Write();
}