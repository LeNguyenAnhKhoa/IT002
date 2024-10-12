// Diem.h
#ifndef DIEM_H
#define DIEM_H

class Diem {
private:
    double x, y;

public:
    Diem(double x = 0, double y = 0);

    // Set coordinates of the point
    void setToaDo(double x, double y);

    // Get x-coordinate
    double getX() const;

    // Get y-coordinate
    double getY() const;

    // Translate the point
    void tinhTien(double dx, double dy);

    // Scale the point
    void phongTo(double factor);

    // Rotate the point around the origin
    void quay(double angle);

    // Print the point coordinates
    void xuat() const;
};

#endif // DIEM_H
