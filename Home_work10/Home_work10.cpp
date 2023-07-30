#include <iostream>

enum class SortingDirection {
	ascending,
	descending
};

bool isSorted(const int* arr, SortingDirection direction) {
	if (int(direction) == int(SortingDirection::descending)) {
		for (int i = 1; i <= 10; ++i) {
			if ((arr + i - 1) >= (arr + i)) {
				std::cout << *arr << std::endl << *(arr + i);
				return false;
			}
		}
	}
	else if (int(direction) == int(SortingDirection::ascending)) {
		for (int i = 1; i <= 10; ++i) {
			if ((arr + i - 1) <= (arr + i)) {
				return false;
			}
		}
	}
	return true;
}

bool find(const int arr[][4], const int toFind) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (arr[i][j] == toFind) return true;
		}
	}
	return false;
}
void traversingArray(int arr[][4]) {
	std::cout << "First way of traversing the array";
	for (int i = 3; i >= 0; --i) {
		if (i % 2 != 0) {
			for (int j = 0; j < 4; ++j) {
				std::cout << arr[i][j] << ' ';
			}
		}
		else {
			for (int j = 3; j >= 0; --j) {
				std::cout << arr[i][j] << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Second way of traversing the array" << std::endl;
	for (int j = 3; j >= 0; --j) {
		for (int i = 0; i < 4; ++i) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	int arr1[4][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	std::cout << "First array:\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << arr1[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	int toFind{};
	std::cout << "Enter number to find in array\n";
	std::cin >> toFind;

	std::cout << std::boolalpha << "This number exist in array is " << find(arr1, toFind);

	int arr2[10]{};
	std::cout << "\nEnter 10 number in array:\n";
	for (int i = 0; i < 10; ++i) {
		std::cin >> arr2[i];
	}
	std::cout << std::boolalpha << "\nThis array is ascending is " << isSorted(arr2, SortingDirection::ascending) << std::endl
		<< "\nThis array is descending is " << isSorted(arr2, SortingDirection::descending);

	std::cout << "\nTravesting first array by two ways\n";
	traversingArray(arr1);
}