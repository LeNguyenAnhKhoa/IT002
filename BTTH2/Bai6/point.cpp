#include "point.h"
#include <iostream>
#include <cmath>

#define PI 3.14

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}

void Point::translate(float angle, float distance) {
    float radian = angle * PI / 180.0;
    x += distance * cos(radian);
    y += distance * sin(radian);
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
