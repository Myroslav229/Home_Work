#include <iostream>

int factorialCycle(int count) {
	int fact = 1;
	for (int i = 1; i <= count; ++i) {
		fact = fact * i;
	}
	std::cout << fact << std::endl;
	return 0;
}
int increaseCycle(int count) {
	for (int i = 1; i <= count; ++i) {
		std::cout << i << std::endl;
	}
	return 0;
}
int decreaseCycle(int count) {
	for (int i = count; i > 0; --i) {
		std::cout << i << std::endl;
	}
	return 0;
}