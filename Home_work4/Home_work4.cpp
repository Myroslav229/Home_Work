#include <iostream>

enum class Month :int {
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};

int main() {
	int first{}, second{}, third{}, counter{};
	std::cout << "Enter first number: ";
	std::cin >> first;
	std::cout << "Enter second number: ";
	std::cin >> second;
	std::cout << "Enter third number: ";
	std::cin >> third;

	if (first >= second) {
		if (first >= third) {
			counter = first;
		}
		else counter = third;

	}
	else {
		if (second >= third) {
			counter = second;
		}
		else counter = third;
	}
	std::cout << "Biggest number is: " << counter << std::endl;


	int fir{}, sec{};
	std::cout << "Enter first number: ";
	std::cin >> fir;
	std::cout << "Enter second number: ";
	std::cin >> sec;
	int smlr = (fir < sec) ? fir : sec;
	std::cout << "Smaller number: " << smlr << std::endl;

	int num{};
	std::cout << "Enter number: ";
	std::cin >> num;
	if (num % 11 == 0 && num % 5 == 0) std::cout << "Тumber is divisible by 5 and 11\n";
	else std::cout << "Тumber is not divisible by 5 and 11\n";

	int alpha{}, beta{}, gamma{};
	std::cout << "Enter angles(degree): ";
	std::cin >> alpha >> beta >> gamma;
	if (alpha + beta + gamma == 180) std::cout << "Triangle can be built\n";
	else std::cout << "Triangle can't be built\n";


	int mon{};
	std::cout << "Enter number of month: ";
	std::cin >> mon;
	Month month = static_cast <Month> (mon);

	switch (month) {
	case Month::January:
		std::cout << "January ";
		break;
	case Month::February:
		std::cout << "February ";
		break;
	case Month::March:
		std::cout << "March ";
		break;
	case Month::April:
		std::cout << "April ";
		break;
	case Month::May:
		std::cout << "May ";
		break;
	case Month::June:
		std::cout << "June ";
		break;
	case Month::July:
		std::cout << "July ";
		break;
	case Month::August:
		std::cout << "August ";
		break;
	case Month::September:
		std::cout << "September ";
		break;
	case Month::October:
		std::cout << "October ";
		break;
	case Month::November:
		std::cout << "November ";
		break;
	case Month::December:
		std::cout << "December ";
		break;
	default:
		std::cout << "Entered wrong number ";
	}
	if (mon < 0 || mon >12) std::cout << "season can't be determined.";
	else if (mon == 12 || mon == 1 || mon == 2) std::cout << "Winter.";
	else if (mon == 3 || mon == 4 || mon == 5) std::cout << "Spring.";
	else if (mon == 6 || mon == 7 || mon == 8) std::cout << "Summer.";
	else std::cout << "Autumn";
	return 0;
}