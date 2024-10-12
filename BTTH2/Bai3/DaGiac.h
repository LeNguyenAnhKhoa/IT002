// DaGiac.h
#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"

class DaGiac {
private:
    int n;      // Number of vertices
    Diem* Dinh; // Array of vertices

public:
    DaGiac();
    ~DaGiac();

    // Input polygon vertices
    // Input: None
    // Output: None (modifies the object)
    void Nhap();

    // Output polygon vertices
    // Input: None
    // Output: None (prints to console)
    void Xuat() const;

    // Translate the polygon
    // Input: dx, dy - translation distances
    // Output: None (modifies the object)
    void TinhTien(double dx, double dy);

    // Scale the polygon
    // Input: factor - scaling factor
    // Output: None (modifies the object)
    void PhongTo(double factor);

    // Shrink the polygon
    // Input: factor - shrinking factor
    // Output: None (modifies the object)
    void ThuNho(double factor);

    // Rotate the polygon around the first vertex
    // Input: angle - rotation angle in degrees
    // Output: None (modifies the object)
    void Quay(double angle);
};

#endif // DAGIAC_H
