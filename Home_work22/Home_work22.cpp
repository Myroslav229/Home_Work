#include <iostream>

#include"InplaceArray.h"


int main()
{
	InplaceArray <int, 4> arr;
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	std::cout << "Size of array: " << arr.getSize() << " Capacity of array: " << arr.getCapacity() << std::endl;
	arr.push_back(3);
	arr.push_back(5);
	std::cout << "Size of array: " << arr.getSize() << " Capacity of array: " << arr.getCapacity() << std::endl;
}