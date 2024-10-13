#include "list.h"
#include <iostream>

// Constructor: Initialize an empty list
List::List() : array(nullptr), size(0) {}

// Destructor: Free the dynamically allocated memory
List::~List() {
    delete[] array;
}

// Add an element to the list
// Input: x - the value to add
// Output: None
void List::add(double x) {
    double* newArray = new double[size + 1];
    for (unsigned int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    newArray[size] = x;
    delete[] array;
    array = newArray;
    ++size;
}

// Remove the first occurrence of x from the list
// Input: x - the value to remove
// Output: None
void List::removeFirst(double x) {
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == x) {
            for (unsigned int j = i; j < size - 1; ++j) {
                array[j] = array[j + 1];
            }
            --size;
            return;
        }
    }
}

// Remove all occurrences of x from the list
// Input: x - the value to remove
// Output: None
void List::removeAll(double x) {
    unsigned int writeIndex = 0;
    for (unsigned int readIndex = 0; readIndex < size; ++readIndex) {
        if (array[readIndex] != x) {
            array[writeIndex] = array[readIndex];
            ++writeIndex;
        }
    }
    size = writeIndex;
}

// Replace the element at the given index with y
// Input: index - the position to replace, y - the new value
// Output: None
void List::replace(unsigned int index, double y) {
    if (index < size) {
        array[index] = y;
    }
}

// Get the current size of the list
// Input: None
// Output: The size of the list
unsigned int List::getSize() const {
    return size;
}

// Get the element at the given index
// Input: index - the position to retrieve
// Output: The value at the given index, or 0 if index is invalid
double List::get(unsigned int index) const {
    if (index < size) {
        return array[index];
    }
    return 0; // Return 0 for invalid index
}

// Print the list in the format [a,b,c,d,...]
// Input: None
// Output: None (prints to console)
void List::print() const {
    std::cout << "[";
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << array[i];
        if (i < size - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}
