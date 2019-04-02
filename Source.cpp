#include <iostream>
#include <fstream>
using namespace std;

struct elem {
	int value;
	elem* next;
};

class Queue {
	elem* top;
	elem* getLastElem();
public:
	Queue();
	~Queue();
	void push(int);
	bool pop(int&);
	bool peek(int&);
	void save(char[]);
	void load(char[]);
};

Queue::Queue() {
	top = nullptr;
}

Queue::~Queue() {
	if (top) {
		elem* temp = top->next;
		while (temp) {
			delete top;
			top = temp;
			temp = temp->next;
		}
		delete top;
	}
}

elem* Queue::getLastElem() {
	if (!top) return top;
	elem* last = top;
	while (last->next) {
		last = last->next;
	}

	return last;
}

void Queue::push(int value) {
	elem *newElem = new elem();
	newElem->value = value;
	newElem->next = nullptr;
	if (top) {
		this->getLastElem()->next = newElem;
	}
	else {
		top = newElem;
	}
}

bool Queue::pop(int& value) {
	if (top) {
		value = top->value;
		elem* temp = top;
		top = top->next;
		delete temp;

		return true;
	}
	return false;
}

bool Queue::peek(int& value) {
	if (top) {
		value = top->value;
		return true;
	}
	return false;
}

void Queue::save(char fname[]) {
	ofstream fout(fname);

	if (top) {
		elem* temp = top;
		while (temp) {
			fout << temp->value << ' ';
			temp = temp->next;
		}
	}

	fout.close();
}

class car
{
private:
	char* regNo;

};

class Lane
{
private:
	int ID;
	Queue carRows[];
public:
	Lane(int new_ID, int carRowCount)
	{
		delete[] carRows;
		ID = new_ID;
		Queue* carRows = new Queue[carRowCount];
	}
	void addCar(car a, int b)
	{
		carRows[b].push(a);
	}
};


int main()
{
	cout << "Hello world!" << endl;
	return 0;
}
