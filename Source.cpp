#include <iostream>
using namespace std;

void increment_pointer(int* value)
{
	(*value)++;
}

void increment_reference(int& value)
{
	value++;
}


//First prime number after value
int replace(int &value)
{
	int temp = value + 1;
	while (true)
	{
		bool isPrime = true;
		for (int i = 2; i <= temp / 2; i++)
		{
			if (temp % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime == true)
		{
			return temp;
		}
		else temp++;
	}
}


//first prime number after value
int replacePointer(int *value)
{
int temp = *value + 1;
while (true)
{
	bool isPrime = true;
	for (int i = 2; i <= temp / 2; i++)
	{
		if (temp % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime == true)
	{
		return temp;
	}
	else temp++;
}
}

//Prints the adress of the first negative number
int* firstNegative(int* arr, int size)
{
	int* ptr = nullptr;

	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) < 0)
		{
			ptr = (arr + i);
		}
	}
	return ptr;
}

//Prints the adress of the first row that contains a given symbol
char* rowWithSymbol(char matrix[][5], int rows, int columns, char symbol)
{
	char *ptr = NULL;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (*(*(matrix + i) + j) == symbol)
			{
				ptr = matrix[i];
				break;
			}
		}
	}
	return ptr;
}

//Counts the number of integers that are greater than 5
void numberFive(int *arr, int n)
{
	int br = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) > 5)
		{
			br++;
		}
	}
	cout << br << endl;
}

//Makes a chess board
void* chess(char a[][8])
{
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					*(*(a + i) + j) = 'w';
				}
				else *(*(a + i) + j) = 'b';
			}
		}
		if (i % 2 == 1)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					*(*(a+i) + j) = 'b';
				}
				else *(*(a + i) + j) = 'w';
			}
		}
	}
	return a;
}

int main()
{
	char arr[8][8];
	chess(arr);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << *(*(arr + i) + j) << " "; 
		}
		cout << endl;
	}
}