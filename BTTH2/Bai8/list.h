#ifndef LIST_H
#define LIST_H

class List {
private:
    double* array;
    unsigned int size;

public:
    // Constructor
    List();

    // Destructor
    ~List();

    // Add an element to the list
    void add(double x);

    // Remove the first occurrence of x
    void removeFirst(double x);

    // Remove all occurrences of x
    void removeAll(double x);

    // Replace the element at index with y
    void replace(unsigned int index, double y);

    // Get the current size of the list
    unsigned int getSize() const;

    // Get the element at index
    double get(unsigned int index) const;

    // Print the list
    void print() const;
};

#endif // LIST_H
