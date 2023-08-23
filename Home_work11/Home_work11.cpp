#include <iostream>
enum class SortingDirection {
    Rows,
    Colums
};
void write(int arr[], const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
	std::cout << std::endl;
}
void write(int arr[], const int rows, const int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i * rows + j]<< ' ';
        }
        std::cout << std::endl;
    }
}
void bubbleSort(int arr[], int size) {
	int minIndex = 0;
	for (int i = 0; i < (size - 1); ++i) {
		minIndex = i;
		for (int j = (i + 1); j < size; ++j) {
			if (arr[j] > arr[minIndex]) minIndex = j;
		}
		if (minIndex != i)std::swap(arr[minIndex], arr[i]);
	}
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    // idx of greater element
    int pointerIdx = (low - 1);
    
    for (int j = low; j < high; j++)
    {
        //std::cout << array[j] << ' ';
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            pointerIdx++;

            // swap element at i with element at j
            std::swap(array[pointerIdx], array[j]);
        }
        
        //std::cout << std::endl;
    }

    std::swap(array[pointerIdx + 1], array[high]);

    return (pointerIdx + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(array, low, high);
        quickSort(array, low, partition_idx - 1);
        quickSort(array, partition_idx + 1, high);
    }
}

void quickSorting2D(int arr[], const int rows, const int columns, SortingDirection direction) {

    
    int low = 0;
    if (direction == SortingDirection::Rows) {

        int high = rows - 1;
        for (int i = 0; i < rows; ++i) {
            quickSort(&arr[i * rows], low, high);
        }
    }
    else if (direction == SortingDirection::Colums) { 
        int high = rows-1;
        std::cout << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = i+1; j < columns; j++) {
                std::swap(arr[i * rows + j], arr[j * columns + i]);
            }
        }
        for (int i = 0; i < columns; ++i) {
            quickSort(&arr[i*columns], low, high);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = i+1; j < columns; j++) {
                std::swap(arr[i * rows + j], arr[j * columns + i]);
            }
        }
    }
    else ;
}
int main()
{
    const int size = 5;
    int array1[size]{23, 43, 15, 7, 19};
	std::cout << "First array before sorting: \n";
    write(array1, size);
    bubbleSort(array1, size);
	std::cout << "First array after bubble sorting: \n";
    write(array1, size);
    
    const int rows = 4;
    const int columns = 4;
    int array2[rows][columns]{ {3,3,2,5}, {4,3,6,2}, {9, 9, 8, 4}, {6,7,8,4}};
    std::cout << "Second array before sorting:\n";
    write(&array2[0][0], rows, columns);
    std::cout << "Second array before sorting:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << &array2[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    //quickSorting2D(&array2[0][0], rows, columns, SortingDirection::Rows);
    std::cout << "Second array after sorting by rows:\n";
    //write(&array2[0][0], rows, columns);
    quickSorting2D(&array2[0][0], rows, columns, SortingDirection::Colums);
    std::cout << "Second array after sorting by columns:\n";
    write(&array2[0][0], rows, columns);
}

