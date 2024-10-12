// main.cpp
#include <iostream>
#include "Triangle.h"

int main() {
    Triangle triangle(Point(), Point(1, 0), Point(0, 1));

    std::cout << "Tam giac ban dau:\n";
    triangle.Xuat();

    triangle.Nhap();
    std::cout << "\nTam giac sau khi nhap:\n";
    triangle.Xuat();
    triangle.Quay(30);
    triangle.TinhTien(3, 3);
    triangle.Xuat();

    return 0;
}
