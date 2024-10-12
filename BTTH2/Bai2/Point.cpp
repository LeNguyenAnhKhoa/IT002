// Point.cpp
#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}

void Point::setCoordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::translate(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::scale(double factor) {
    x *= factor;
    y *= factor;
}

void Point::rotate(double angle) {
    double radians = angle * M_PI / 180.0;
    double newX = x * cos(radians) - y * sin(radians);
    double newY = x * sin(radians) + y * cos(radians);
    x = newX;
    y = newY;
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
