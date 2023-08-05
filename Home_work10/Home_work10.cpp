#include <iostream>

enum class SortingDirection {
	ascending,
	descending
};

bool isSorted(const int arr[], const int size, SortingDirection direction) {
	if (direction == SortingDirection::descending) {
		for (int i = 1; i < size; ++i) {
			if (arr [i - 1] <= arr [i]) {
				
				return false;
			}
		}
	}
	else if (direction == SortingDirection::ascending) {
		for (int i = 1; i < size; ++i) {
			if (arr [i - 1] >= arr [i]) {
				return false;
			}
		}
	}
	return true;
}

bool find(int arr[], const int rows, const int columns, const int toFind) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (arr[i * rows + j] == toFind) return true;
		}
	}
	return false;
}
void traversingArray(int arr[], const int rows, const int columns) {
	std::cout << "First way of traversing the array";
	for (int i = rows - 1; i >= 0; --i) {
		if (i % 2 != 0) {
			for (int j = 0; j < columns; ++j) {
				std::cout << arr[i * rows + j] << ' ';
			}
		}
		else {
			for (int j = columns - 1; j >= 0; --j) {
				std::cout << arr[i * rows + j] << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Second way of traversing the array" << std::endl;
	for (int j = columns - 1; j >= 0; --j) {
		for (int i = 0; i < rows; ++i) {
			std::cout << arr[i * rows + j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	const int rows = 4, columns = 4;
	int arr1[rows][columns]{ {1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16} };
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

	std::cout << std::boolalpha << "This number exist in array is " << find(&arr1[0][0], rows, columns, toFind);

	const int arraySize = 10;
	int arr2[arraySize]{};
	std::cout << "\nEnter 10 number in array:\n";
	for (int i = 0; i < 10; ++i) {
		std::cin >> arr2[i];
	}
	std::cout << std::boolalpha << "\nThis array is ascending is " << isSorted(arr2, arraySize, SortingDirection::ascending) << std::endl
		<< "\nThis array is descending is " << isSorted(arr2, arraySize, SortingDirection::descending);

	std::cout << "\nTravesting first array by two ways\n";
	traversingArray(&arr1[0][0],rows,columns);
}
