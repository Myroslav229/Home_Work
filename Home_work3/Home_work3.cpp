#include <iostream>
#include <iomanip>



int main() {
	int sec, min = 0, hour = 0;
	std::cout << "Enter time(sec): ";
	std::cin >> sec;
	hour = sec / 360;
	std::cout << "Hours: " << hour << std::endl;
	sec = sec - hour * 360;
	min = sec / 60;
	std::cout << "Minutes: " << min << std::endl;
	sec = sec - min * 60;
	std::cout << "Seconds: " << sec << std::endl;


	float a{}, b{}, c{};
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	std::cout << "Enter third number: ";
	std::cin >> c;
	float sum = a + b + c;
	float prod = a * b * c;
	float arithmetic_mean = sum / 3;
	std::cout << "Sum of numbers: " << sum << std::endl;
	std::cout << "Product of numbers: " << prod << std::endl;
	std::cout << "Arithmetic mean of numbers: " << arithmetic_mean << std::endl;
	std::cout << "First number more than second is " << std::boolalpha << (a > b) << std::endl;
	std::cout << "Second number more than third is " << std::boolalpha << (b > c) << std::endl;

	int first{}, second{};
	bool lessThan = first < second;
	bool equal = first == second;
	bool moreThan = first > second;
	bool lessOrEqual = first <= second;
	std::cout << "The first number is relative to the second is...\n";
	std::cout << "Less: " << std::boolalpha << lessThan << std::endl;
	std::cout << "Equal: " << std::boolalpha << equal << std::endl;
	std::cout << "More: " << std::boolalpha << moreThan << std::endl;
	std::cout << "Less or equal: " << std::boolalpha << lessOrEqual << std::endl;

	int width{}, height{};
	std::cout << "Enter width of rectangle: ";
	std::cin >> width;
	std::cout << "Enter height of rectangle: ";
	std::cin >> height;
	int area = width * height;
	int perimeter = 2 * (width + height);
	std::cout << "Area of rectangle: " << area << std::endl;
	std::cout << "Perimeter of rectangle: " << perimeter << std::endl;

	const float pi = 3.14;
	int radius{};
	std::cout << "Enter radius of circle: ";
	std::cin >> radius;
	float circleArea = pi * radius * radius;
	float circuit = 2 * pi * radius;
	std::cout << "Area of cirle: " << circleArea << std::endl;
	std::cout << "Circuit: " << circuit << std::endl;

	return 0;
}