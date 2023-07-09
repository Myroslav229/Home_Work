#include <iostream>

int factorialCycle(int count) {
	int fract = 1;
	for (int i = 1; i <= count; ++i) {
		fract = fract * i;
	}
	std::cout << fract << std::endl;
	return 0;
}
int increaseCycle(int count) {
	for (int i = 1; i <= count; ++i) {
		std::cout << i << std::endl;
	}
	return 0;
}
int reductionCycle(int count) {
	for (int i = count; i > 0; --i) {
		std::cout << i << std::endl;
	}
	return 0;
}