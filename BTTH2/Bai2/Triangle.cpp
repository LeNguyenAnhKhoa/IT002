// Triangle.cpp
#include "Triangle.h"
#include <iostream>

Triangle::Triangle(const Point& A, const Point& B, const Point& C) : A(A), B(B), C(C) {}

void Triangle::Nhap() {
    double x, y;
    std::cout << "Nhap toa do diem A:\n";
    std::cin >> x >> y;
    A.setCoordinates(x, y);

    std::cout << "Nhap toa do diem B:\n";
    std::cin >> x >> y;
    B.setCoordinates(x, y);

    std::cout << "Nhap toa do diem C:\n";
    std::cin >> x >> y;
    C.setCoordinates(x, y);
}

void Triangle::Xuat() const {
    std::cout << "Tam giac voi cac dinh:\n";
    std::cout << "A: ";
    A.print();
    std::cout << "\nB: ";
    B.print();
    std::cout << "\nC: ";
    C.print();
    std::cout << std::endl;
}

void Triangle::TinhTien(double dx, double dy) {
    A.translate(dx, dy);
    B.translate(dx, dy);
    C.translate(dx, dy);
}

void Triangle::PhongTo(double factor) {
    B.scale(factor);
    C.scale(factor);
}

void Triangle::ThuNho(double factor) {
    PhongTo(1.0 / factor);
}

void Triangle::Quay(double angle) {
    B.rotate(angle);
    C.rotate(angle);
}
