#include <iostream>
#include "Cycles.h"
#include "Recursion.h"

int counter(int count) {
	int neg = 0, pos = 0, zero = 0;
	for (int ans = 0; ans < count; ++ans) {
		int a = 0;
		std::cin >> a;
		if (a < 0) neg++;
		else if (a > 0) pos++;
		else zero++;
	}
	std::cout << "Number of zeros: " << zero << std::endl << "Number of negative: " << neg << std::endl << "Number of positive:" << pos << std::endl;
	return 0;
}

int main()
{
	int a{}, b{};
	std::cout << "Enter number for input: ";
	std::cin >> b;
	counter(b);
	std::cout << "Enter number for calculations: ";
	std::cin >> a;
	std::cout << "Factorial calculated by cycle: " << std::endl;
	factorialCycle(a);
	std::cout << "Increase calculated by cycle: " << std::endl;
	increaseCycle(a);
	std::cout << "Reduction calculated by cycle: " << std::endl;
	reductionCycle(a);
	std::cout << "Factorial calculated by recursion: " << std::endl;
	factorialRecursion(a);
	std::cout << "Increase calculated by recursion: " << std::endl;
	increaseRecursion(a);
	std::cout << "Reduction calculated by recursion: " << std::endl;
	reductionRecursion(a);
}
