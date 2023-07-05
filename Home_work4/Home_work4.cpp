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
	int first{}, second{}, third{}, max{};
	std::cout << "Enter first number: ";
	std::cin >> first;
	std::cout << "Enter second number: ";
	std::cin >> second;
	std::cout << "Enter third number: ";
	std::cin >> third;

	if (first >= second) {
		if (first >= third) {
			max = first;
		}
		else max = third;

	}
	else {
		if (second >= third) {
			max = second;
		}
		else max = third;
	}
	std::cout << "Maximum is: " << max << std::endl;


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
	if (num % 11 == 0 && num % 5 == 0) std::cout << "Number is divisible by 5 and 11\n";
	else std::cout << "Number is not divisible by 5 and 11\n";

	int alpha{}, beta{}, gamma{};
	std::cout << "Enter angles(degree): ";
	std::cin >> alpha >> beta >> gamma;
	if (alpha + beta + gamma == 180 && alpha < 0 && beta < 0 && gamma < 0) std::cout << "Triangle can be built\n";
	else std::cout << "Triangle can't be built\n ";


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
	switch (mon) {
	case 12:
	case 1:
	case 2:
		std::cout << "Winter.";
		break;
	case 3:
	case 4:
	case 5:
		std::cout << "Spring.";
		break;
	case 6:
	case 7:
	case 8:
		std::cout << "Summer.";
		break;
	case 9:
	case 10:
	case 11:
		std::cout << "Autumn.";
		break;
	default:
		std::cout << "season can't be determined.";
	}
	return 0;
}