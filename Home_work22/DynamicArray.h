#pragma once
#include <iostream>
template <typename T> class DynamicArray {
private:
    std::size_t size = 0;
    std::size_t capacity = 0;
    T* data;
public:

    //default c-tor
    DynamicArray() {
        data = new T[size]{};
    };

    //c-tor with size
    DynamicArray(std::size_t size) {
        this->size = size;
        capacity = size;
        data = new T[size]{};
    };

    //copy c-tor
    DynamicArray(const DynamicArray& other) {
        this->size = other.size;
        capacity = other.capacity;
        data = new T[size]{};
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i];
        }
    };

    //free allocated memory
    ~DynamicArray() {
        delete[] data;
    };

    DynamicArray& operator=(const DynamicArray& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] data;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    };

    T& operator[](std::size_t index) {
        return data[index];
    };

    bool operator==(DynamicArray& other) {
        if (size == other.size) {
            for (int i = 0; i < size; ++i) {
                if (data[i] != other.data[i]) return false;
            }
            return true;
        }
        else return false;
    }
    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize) {
        delete[] data;
        size = newSize;
        capacity = size;
        data = new T[size]{};
    };
    std::size_t getSize() const {
        return this->size;
    };

    //Clear internal memory, set size to 0
    void clear() {
        delete[] data;
        size = 0;
        data = new T[size]{};
    };


    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(int element) {
        if (capacity > size) {
            data[size] = element;
            size += 1;
        }
        else {
            int* newArray = new T[size + 1]{};
            for (int i = 0; i < size; ++i) {
                newArray[i] = data[i];
            }
            newArray[size] = element;
            size += 1;
            capacity = size;
            delete[] data;
            data = newArray;
        }

    };

    void reserve(std::size_t newCapacity) {
        if (newCapacity > capacity) {
            int* newArray = new T[newCapacity]{};
            for (int i = 0; i < size; ++i) {
                newArray[i] = data[i];
            }
            capacity = newCapacity;
            delete[] data;
            data = newArray;
        }
    }
    void shrinkToFit() {
        if (capacity > size) {
            int* newArray = new T[size]{};
            for (int i = 0; i < size; ++i) {
                newArray[i] = data[i];
            }
            capacity = size;
            delete[] data;
            data = newArray;
        }
    }
    std::size_t getCapacity() const {
        return capacity;
    }
    void popBack() {
        data[size - 1] = 0;
        size -= 1;
    }
    T& Back() const {
        return data[size - 1];
    }
};