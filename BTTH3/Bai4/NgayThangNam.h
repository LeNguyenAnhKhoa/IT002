#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    // Constructor mac dinh
    NgayThangNam();

    // Constructor tham so
    NgayThangNam(int ngay, int thang, int nam);

    // Phuong thuc tinh tong so ngay tinh tu nam 0
    int TinhNgay() const;

    // Operator + them ngay
    NgayThangNam operator+(int ngay);

    // Operator - tru ngay
    NgayThangNam operator-(int ngay);

    // Operator tru hai doi tuong NgayThangNam
    int operator-(const NgayThangNam& a);

    // Operator ++ (tang 1 ngay)
    NgayThangNam& operator++();

    // Operator -- (giam 1 ngay)
    NgayThangNam& operator--();

    // Operator so sanh
    bool operator==(const NgayThangNam& a);
    bool operator!=(const NgayThangNam& a);
    bool operator>=(const NgayThangNam& a);
    bool operator<=(const NgayThangNam& a);
    bool operator>(const NgayThangNam& a);
    bool operator<(const NgayThangNam& a);

    // Nhap va xuat
    friend istream& operator>>(istream& is, NgayThangNam& a);
    friend ostream& operator<<(ostream& os, const NgayThangNam& a);
};

#endif
