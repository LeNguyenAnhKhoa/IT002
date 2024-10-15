#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

public:
    // Ham tao mac dinh
    // Input: Khong co
    // Output: Khoi tao phan so 0/1
    PhanSo();

    // Ham tao co tham so
    // Input: Tu so va mau so
    // Output: Khoi tao phan so voi tu va mau da cho
    PhanSo(int Tu, int Mau);

    // Cac phuong thuc toan tu
    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;
    bool operator==(const PhanSo& other) const;
    bool operator!=(const PhanSo& other) const;
    bool operator>=(const PhanSo& other) const;
    bool operator<=(const PhanSo& other) const;
    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;

    // Phuong thuc nhap xuat
    friend istream& operator>>(istream& is, PhanSo& ps);
    friend ostream& operator<<(ostream& os, const PhanSo& ps);

private:
    // Ham rut gon phan so
    // Input: Tu so va mau so
    // Output: Rut gon phan so hien tai
    void RutGon();
};

#endif
