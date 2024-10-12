// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point A, B, C;

public:
    Triangle(const Point& A, const Point& B, const Point& C);
    void Nhap();
    void Xuat() const;
    void TinhTien(double dx, double dy);
    void PhongTo(double factor);
    void ThuNho(double factor);
    void Quay(double angle);
};

#endif // TRIANGLE_H
