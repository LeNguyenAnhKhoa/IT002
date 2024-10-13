#include "triangle.h"
#include <iostream>

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}

void Triangle::translate(float angle, float distance) {
    p1.translate(angle, distance);
    p2.translate(angle, distance);
    p3.translate(angle, distance);
}

void Triangle::print() const {
    std::cout << "Triangle: ";
    p1.print();
    std::cout << " ";
    p2.print();
    std::cout << " ";
    p3.print();
    std::cout << std::endl;
}
