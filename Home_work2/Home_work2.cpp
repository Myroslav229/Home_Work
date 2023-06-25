#include <iostream>
#include <iomanip>

enum WeekDay {
	Monday = 0,
	Tuesdey = 1,
	Wednesday = 2,
	Thursday = 3,
	Friday = 4,
	Saturday = 5,
	Sunday = 6
};

int main() {
	int first;
	int second;
	int buffer = 0;

	std::cout << "Enter first number: ";
	std::cin >> first;
	std::cout << "Enter second number: ";
	std::cin >> second;
	buffer = first;
	first = second;
	second = buffer;
	std::cout << "First number: " << first << std::endl;
	std::cout << "Second number: " << second << std::endl;


	double align = 6.766;

	std::cout << "Number to align: " << align << std::endl;
	std::cout << "Nithout a decimal part: " << (int)align << std::endl;
	std::cout << "Aligned: " << std::setw(20) << std::right << std::setfill('$') << align << std::endl;


	double accur = 3434.6666667;

	std::cout << "Up to 2 standart: " << std::fixed << std::setprecision(2) << accur << std::endl;
	std::cout << "Up to 5 standart: " << std::fixed << std::setprecision(5) << accur << std::endl;
	std::cout << "Up to 100 standart: " << std::fixed << std::setprecision(10) << accur << std::endl;

	std::cout << "Up to 2 scientific: " << std::setprecision(2) << std::scientific << accur << std::endl;
	std::cout << "Up to 5 scientific: " << std::setprecision(5) << std::scientific << accur << std::endl;
	std::cout << "Up to 10 scientific: " << std::setprecision(10) << std::scientific << accur << std::endl;


	std::cout << " Number of Monday: " << (int)Monday << std::endl;
	std::cout << " Number of Monday: " << (int)Tuesdey << std::endl;
	std::cout << " Number of Monday: " << (int)Wednesday << std::endl;
	std::cout << " Number of Monday: " << (int)Thursday << std::endl;
	std::cout << " Number of Monday: " << (int)Friday << std::endl;
	std::cout << " Number of Monday: " << (int)Saturday << std::endl;
	std::cout << " Number of Monday: " << (int)Sunday << std::endl;


	bool b;

	std::cout << "Enter bool number: ";
	std::cin >> b;
	std::cout << "Result: " << std::boolalpha << b << std::endl;

	return 0;
}