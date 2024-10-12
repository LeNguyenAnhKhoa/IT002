// Diem.cpp
#include "Diem.h"
#include <iostream>
#include <cmath>

Diem::Diem(double x, double y) : x(x), y(y) {}

void Diem::setToaDo(double x, double y) {
    this->x = x;
    this->y = y;
}

double Diem::getX() const { return x; }
double Diem::getY() const { return y; }

void Diem::tinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

void Diem::phongTo(double factor) {
    x *= factor;
    y *= factor;
}

void Diem::quay(double angle) {
    double radians = angle * M_PI / 180.0;
    double newX = x * cos(radians) - y * sin(radians);
    double newY = x * sin(radians) + y * cos(radians);
    x = newX;
    y = newY;
}

void Diem::xuat() const {
    std::cout << "(" << x << ", " << y << ")";
}
