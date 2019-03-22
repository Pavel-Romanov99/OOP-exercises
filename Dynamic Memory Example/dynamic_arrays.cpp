#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int* read(int x)
{
	int* arr = new int[x];

	for (int i = 0; i < x; i++)
	{
		cin >> arr[i];
	}
	return arr;
}

void resize(int*& arr, int size, int newSize)
{
	assert(newSize > size);
	assert(arr != nullptr);

	int* newArr = new int[newSize];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void addElements(int *&arr, int size, int numbers)
{
	resize(arr, size, size + numbers);

	for (int i = size; i < size + numbers; i++)
	{
		cin >> arr[i];
	}
}

int* erase(int * arr, int size, int left_index, int right_index)
{
	int* ans = new int[size - (right_index - left_index + 1)];

	for (int i = 0; i < left_index; i++)
	{
		ans[i] = arr[i];
	}
	for (int i = right_index + 1; i < size; i++)
	{
		ans[i - (right_index - left_index + 1)] = arr[i];
	}
	return ans;
}

int* erase_index(int *arr, int size, int index)
{
	return erase(arr, size, index, index);
}

int* extend(int * arr, int size, int num)
{
	resize(arr, size, num);

	for (int i = size; i < size + num; i++)
	{
		arr[i] = 0;
	}
	return arr;
}

int main()
{
	size_t sizeOfArray = 10;

	int * arr = new int[sizeOfArray] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Test single index erase
	int * result = erase_index(arr, sizeOfArray, 1);
	cout << "Erasing elements at index 1: " << endl;
	cout << "Array: ";
	for (size_t i = 0; i < sizeOfArray - 1; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	delete[] result;

	result = erase(arr, sizeOfArray, 0, 3);
	cout << "Erasing elements at indexes [0, 3]: " << endl;
	cout << "Array: ";
	for (size_t i = 0; i < sizeOfArray - 4; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] result;
	delete[] arr;
}
