#pragma once
class DynamicIntArray
{
private:
    std::size_t arrSize = 0;
    int* array;
public:

    //default c-tor
    DynamicIntArray() {
        array = new int[arrSize] {};
    };

    //c-tor with size
    DynamicIntArray(std::size_t size) {
        arrSize = size;
        array = new int[arrSize] {};
    };

    //copy c-tor
    DynamicIntArray(const DynamicIntArray& other) {
        arrSize = other.arrSize;
        array = new int[arrSize] {};
        for (int i = 0; i < other.arrSize; ++i) {
            array[i] = other.array[i];
        }
    };

    //free allocated memory
    ~DynamicIntArray() {
        delete[] array;
    };

    DynamicIntArray& operator=(const DynamicIntArray& other) {
        this->arrSize = other.arrSize;
        delete[] array;
        array = new int[arrSize];
        for (int i = 0; i < arrSize; ++i) {
            array[i] = other.array[i];
        }
        return *this;
    };

    int& operator[](std::size_t index) {
        return array[index];
    };

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize) {
        delete[] array;
        arrSize = newSize;
        array = new int[arrSize] {};
    };
    std::size_t getSize() const {
        return this->arrSize;
    };

    //Clear internal memory, set size to 0
    void clear() {
        delete[] array;
        arrSize = 0;
        array = new int [arrSize] {};
    };


    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(int element) {
        int* newArray = new int[arrSize + 1] {};
        for (int i = 0; i < arrSize; ++i) {
            newArray[i] = array[i];
        }
        newArray[arrSize] = element;
        arrSize += 1;
        delete[] array;
        array = newArray;
    };
};