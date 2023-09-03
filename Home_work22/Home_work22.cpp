#include <iostream>

#include"InplaceArray.h"

int main()
{
	InplaceArray <int, 4> arr;
	arr.pushBack(3);
	arr.pushBack(2);
	arr.pushBack(22);
	std::cout << "Array size: " <<  arr.getSize() << ", capacity: " << arr.getCapacity() << std::endl;
	arr.pushBack(3);
	arr.pushBack(1);
	std::cout << "Array size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << std::endl;
}