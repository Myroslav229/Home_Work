#include <iostream>


int factorialRecursion(int count) {
	if (count > 1) return count * factorialRecursion(count - 1);
	else return count;
}
int increaseRecursion(int count) {
	if (count > 1) {
		increaseRecursion(count - 1);
	}
	std::cout << count << std::endl;
	return 0;
}
int decreaseRecursion(int count) {
	std::cout << count << std::endl;
	if (count > 1) {
		decreaseRecursion(count - 1);
	}
	return 0;
}