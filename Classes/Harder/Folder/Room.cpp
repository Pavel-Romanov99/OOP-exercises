#include "Header.h"

Room::Room()
{
	this->capacity = 10;
	this->size = 0;
	ElectricalDevice** list = new ElectricalDevice*[capacity];
}

Room::~Room()
{
	delete[] list;
}

void Room::addDevice(ElectricalDevice *ptr)
{
	if (size < capacity)
	{
		list[size] = ptr;
		size++;
	}
}

void Room::Alert()
{
	for (int i = 0; i < size + 1; i++)
	{
		list[i]->Alert();
	}
}

int Room::costNumberofDays(int x)
{
	int sum = 0;
	for (int i = 0; i < capacity; i++)
	{
		sum += list[i]->get_energy()* x;
	}
	return sum;
}

Room::Room(const Room &other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	delete[] list;

	list = new ElectricalDevice*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		list[i] = other.list[i];
	}
}
