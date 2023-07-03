#include <iostream>
# include <cctype>


int main() {
	int a{}, step{}, number{};
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter step of arithmetic sequence: ";
	std::cin >> step;
	std::cout << "Enter number of arithmetic sequence: ";
	std::cin >> number;
	for (int i = 1; i <= number; i++) {
		std::cout << i << "-st number of arithmetic sequence: " << a << std::endl;
		a = a + step;
	}

	int num{}, Fzero = 0, Ff = 1, Fres{};
	std::cout << "Enter number of Fibonacci sequence: ";
	std::cin >> num;
	for (int i = 1; i < num; i++) {

		Fres = Fzero + Ff;
		Fzero = Ff;
		Ff = Fres;
	}
	std::cout << "Element of Fibonacci sequence: " << Fres << std::endl;

	unsigned int b{}, factorial{};

	std::cout << "Enter number for factorial: ";
	std::cin >> b;
	factorial = b;
	for (int i = 1; i < b; i++) {
		factorial = i * factorial;
	}
	std::cout << factorial << std::endl;

	int size{}, width{}, height{};

	std::cout << "Enter size of triangle: ";
	std::cin >> size;
	std::cout << "Enter width: ";
	std::cin >> width;
	std::cout << "Enter height: ";
	std::cin >> height;
	std::cout << "a.\n";
	for (int i = size; i > 0; --i) {
		for (int j = 0; j <= i; ++j) {
			std::cout << '*';
		}
		std::cout << "\n";
	}
	std::cout << "b.\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j <= i; ++j) {
			std::cout << '*';
		}
		std::cout << "\n";
	}
	std::cout << "c.\n";
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << '*';
		}
		std::cout << "\n";
	}
	std::cout << "d.\n";
	for (int i = 0; i < height; ++i) {
		for (int k = 0; k < i; k++) {
			std::cout << ' ';
		}
		for (int j = 0; j < width; ++j) {
			std::cout << '*';
		}
		std::cout << "\n";
	}
	std::cout << "e.\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j <= i; ++j) {
			if ((j + i) % 2 == 0) std::cout << '1';
			else std::cout << '0';
		}
		std::cout << "\n";
	}
	char c{};
	int sum = 0;
	while (c != '.') {

		std::cin >> c;
		if (std::islower(c)) {
			std::cout << (char)std::toupper(c) << std::endl;
		}
		else if (std::isdigit(c)) {
			sum = sum + c - '0';
			std::cout << sum << std::endl;
		}
		else if (std::iscntrl(c) || std::ispunct(c)) {
			std::cout << "This character is not processed by the program\n";
		}
	}
}