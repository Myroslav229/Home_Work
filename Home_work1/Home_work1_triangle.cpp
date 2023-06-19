#include <iostream>

int main() {
	int size;

	std::cout << "Enter size: " ;
	std::cin >> size;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}