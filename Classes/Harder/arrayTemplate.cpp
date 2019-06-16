#include <iostream>
#include <string>
using namespace std;


template<typename T>
class Array
{
private:
	T * array1;
	int size;
	int capacity;
public:
	int get_capacity() const;
	Array(int capacity);
	~Array();
	Array(const Array &other);
	Array& operator=(const Array& other);
	T& operator[](int sub);
};

template<typename T>
int Array<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
Array<T>::Array(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	array1 = new T[capacity];
}

template<typename T>
Array<T>::~Array()
{
	delete[] array1;
}

template<typename T>
T& Array<T>::operator[](int sub) {
	if (sub < 0 && sub >= capacity)
	{
		cout << "Error" << endl;
		exit(1);
	}
	return array1[sub];
}

template<typename T>
Array<T> & Array<T>::operator=(const Array<T>&p)
{
	delete[] array1;
	capacity = p.capacity;
	array1 = new T[capacity];

	for (int i = 0; i < p.get_capacity(); i++)
	{
		array1[i] = p.array1[i];
	}
	return *this;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	capacity = other.capacity;
	array1 = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		array1[i] = other.array1[i];
	}
}

int main()	
{
	int n; cin >> n;
	Array<double> a(n);
	
	for (int i = 0; i < a.get_capacity(); i++)
	{
		a[i] = i + 0.5;
	}

	for (int i = 0; i < a.get_capacity(); i++)
	{
		cout << a[i] << " ";
	}
}