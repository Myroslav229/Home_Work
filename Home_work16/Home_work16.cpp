#include <iostream>
#include "DynamicIntArray.h"
#include "correction.h"
void randArray(DynamicIntArray& array) {

    for (int i = 0; i < array.getSize(); ++i) {
        //array.push_back(i);
        array[i] = std::rand() % (10 - 1);
    }
}
void outArray(DynamicIntArray& array) {
    for (int i = 0; i < array.getSize(); ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}
int main() {

    DynamicIntArray arr1(10), arr2(arr1);

    randArray(arr1);
    std::cout << "First array: \n";
    outArray(arr1);
    std::cout << "Second array constructed equal first: \n";
    outArray(arr2);
    arr2.clear();
    std::cout << "Second array after clear: \n";
    outArray(arr2);
    arr2.setSize(4);
    std::cout << "Second array after set size:\n";
    outArray(arr2);
    arr2.push_back(4);
    std::cout << "Second array after push back:\n";
    outArray(arr2);
    arr2 = arr1;
    std::cout << "Second array equal first again:\n";
    outArray(arr2);
}