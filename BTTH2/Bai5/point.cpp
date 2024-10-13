// point.cpp
#include "point.h"
#include <iostream>

Point::Point(double x, double y) : x(x), y(y) {}

void Point::doubleCoordinates() {
    x *= 2;
    y *= 2;
}

void Point::resetToOrigin() {
    x = 0;
    y = 0;
}

void Point::translate(int k, double d) {
    if (k == 0) {
        x += d;
    } else {
        y += d;
    }
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
