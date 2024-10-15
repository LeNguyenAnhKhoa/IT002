#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>

using namespace std;

class ThoiGian {
private:
    int iGio;   // Gio
    int iPhut;  // Phut
    int iGiay;  // Giay

public:
    // Constructor mac dinh
    ThoiGian();

    // Constructor co tham so
    ThoiGian(int Gio, int Phut, int Giay);

    // Tinh tong giay tu gio, phut, giay
    int TinhGiay() const;

    // Chuyen tu tong so giay ve gio, phut, giay
    void TinhLaiGio(int Giay);

    // Toan tu cong mot so giay
    ThoiGian operator+(int Giay);

    // Toan tu tru mot so giay
    ThoiGian operator-(int Giay);

    // Toan tu cong hai doi tuong ThoiGian
    ThoiGian operator+(const ThoiGian& tg);

    // Toan tu tru hai doi tuong ThoiGian
    ThoiGian operator-(const ThoiGian& tg);

    // Toan tu tang ++ (tang 1 giay)
    ThoiGian& operator++();

    // Toan tu giam -- (giam 1 giay)
    ThoiGian& operator--();

    // Toan tu so sanh ==
    bool operator==(const ThoiGian& tg);

    // Toan tu so sanh !=
    bool operator!=(const ThoiGian& tg);

    // Toan tu so sanh >=
    bool operator>=(const ThoiGian& tg);

    // Toan tu so sanh <=
    bool operator<=(const ThoiGian& tg);

    // Toan tu so sanh >
    bool operator>(const ThoiGian& tg);

    // Toan tu so sanh <
    bool operator<(const ThoiGian& tg);

    // Toan tu nhap >>
    friend istream& operator>>(istream& is, ThoiGian& tg);

    // Toan tu xuat <<
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
};

#endif
