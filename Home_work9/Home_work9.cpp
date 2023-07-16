#include <iostream>

void swap1(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void swap2(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
bool calculateSum(const double* arr, int arrSize, double& sum) {
	if (arrSize > 0) {
		for (int i = 0; i < arrSize; ++i) {
			sum += arr[i];
		}
		return true;
	}
	else return false;
}

bool find(const int* arr, int size, int elem) {
	for (int i = 0; i < size; ++i) {
		if (elem == *(arr + i)) return true;
	}
	return false;
}

int main() {
	int a{}, b{};
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	int* ptrA = &a;
	int* ptrB = &b;
	swap1(a, b);
	std::cout << "\nFirst number after swap: " << a << "\nSecond number after swap: " << b;
	swap2(ptrA, ptrB);
	std::cout << "\nFirst number after secon swap: " << a << "\nSecond number after second swap: " << b;
	double arr1[]{ 3.44, 7, 9 };
	std::cout << "Array of double ";
	for (int i = 0; i < sizeof(arr1) / sizeof(double); ++i) {
		std::cout << arr1[i] << ' ';
	}
	double sum = 0;
	calculateSum(arr1, sizeof(arr1) / sizeof(double), sum);
	std::cout << "\nSum of array elements " << sum;
	int arr[]{ 1, 4, 5 };
	int searchNumber{};
	std::cout << "\nEnter number for searching inarray: ";
	std::cin >> searchNumber;
	std::cout << std::boolalpha << "Result " << find(arr, sizeof(arr) / sizeof(int), searchNumber);
}