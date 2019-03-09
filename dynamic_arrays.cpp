#include <iostream>
using namespace std;

int *read(size_t n)
{
	int *arr = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return arr;
}

void resize(int *& arr, size_t size, size_t new_size)
{
	int *new_array = new int[new_size];

	for (size_t i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}

	delete[] arr;
	arr = new_array;
}

void add_elements(int *& arr, size_t size, int br_numbers)
{
	resize(arr, size, size + br_numbers);

	for (int i = 0; i < size + br_numbers; i++)
	{
		cin >> arr[i];
	}

}

int* erase(int * arr, size_t size, size_t index)
{
	int * ans = new int[size - 1];
	for (size_t i = 0; i < index; i++)
	{
		ans[i] = arr[i];
	}
	for (size_t i = index + 1; i < size; i++)
	{
		ans[i - 1] = arr[i];
	}

	return ans;
}

void extend(int *& arr, size_t size, size_t newSize)
{
	resize(arr, size, newSize);
	for (size_t i = size; i < newSize; i++)
	{
		arr[i] = 0;
	}
}

int main()
{
	
}