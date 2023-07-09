#include <iostream>

int factorial = 1;
int factorialRecursion(int count) {
	factorial = factorial * count;
	if (count > 1) {
		factorialRecursion(count - 1);
	}
	else {
		std::cout << factorial << std::endl;
		factorial = 1;
	}
	return 0;
}
int increaseRecursion(int count) {
	if (count > 1) {
		increaseRecursion(count - 1);
	}
	std::cout << count << std::endl;
	return 0;
}
int reductionRecursion(int count) {
	std::cout << count << std::endl;
	if (count > 1) {
		reductionRecursion(count - 1);
	}
	return 0;
}