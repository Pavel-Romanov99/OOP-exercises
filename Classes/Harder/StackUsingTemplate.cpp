#include <iostream>
#include <string>
using namespace std;

template<class T>
class Stack
{
private:
	T * items;
	int top;
	int size;
	int capacity;
public:
	Stack();
	Stack(int capacity);
	Stack(Stack& other);
	~Stack();
	void push(T c);
	void pop();
	bool empty() const;
	bool full() const;
	void print();
	int get_size() const;
};

template<typename T>
int Stack<T>::get_size() const
{
	return size;
}

template<typename T>
Stack<T>::Stack()
{
	this->size = 0;
	this->capacity = 50;
	items = new T[capacity];
	this->top = size;
}


template<typename T>
bool Stack<T>::full() const
{
	if (size == capacity)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::empty() const
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] items;
}

template<typename T>
Stack<T>::Stack(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	items = new T[capacity];
	this->top = size;
}

template<typename T>
Stack<T>::Stack(Stack &other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	items = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		items[i] = other.items[i];
	}
}

template<typename T>
void Stack<T>::push(T c)
{
	if (full())
	{
		cout << "Stack is full!" << endl;
		return;
	}
	items[++size] = c;
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "The popped element is " << items[size] << endl;
		size--;
	}

}

template<typename T>
void Stack<T>::print()
{
	if (!this->empty())
	{
		for (int i = 0; i < size + 1 ; i++)
		{
			cout << items[i] << " ";
		}
		cout << endl;
	}

}

int main()
{
	Stack<string> a;
	a.push("Hello");
	a.push("there");
	a.push("little");
	a.push("padawan");
	a.pop();
	a.pop();
	a.print();
	Stack<string> b = a;
	cout << b.get_size() << endl;
}