#include "ThoiGian.h"

// Constructor mac dinh
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Constructor co tham so
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

// Tinh tong so giay tu gio, phut, giay
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Chuyen tu tong so giay ve gio, phut, giay
void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;
}

// Toan tu cong mot so giay
ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian tg;
    tg.TinhLaiGio(totalSeconds);
    return tg;
}

// Toan tu tru mot so giay
ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian tg;
    tg.TinhLaiGio(totalSeconds);
    return tg;
}

// Toan tu cong hai doi tuong ThoiGian
ThoiGian ThoiGian::operator+(const ThoiGian& tg) {
    return *this + tg.TinhGiay();
}

// Toan tu tru hai doi tuong ThoiGian
ThoiGian ThoiGian::operator-(const ThoiGian& tg) {
    return *this - tg.TinhGiay();
}

// Toan tu tang ++ (tang 1 giay)
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

// Toan tu giam -- (giam 1 giay)
ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

// Toan tu so sanh ==
bool ThoiGian::operator==(const ThoiGian& tg) {
    return TinhGiay() == tg.TinhGiay();
}

// Toan tu so sanh !=
bool ThoiGian::operator!=(const ThoiGian& tg) {
    return !(*this == tg);
}

// Toan tu so sanh >=
bool ThoiGian::operator>=(const ThoiGian& tg) {
    return TinhGiay() >= tg.TinhGiay();
}

// Toan tu so sanh <=
bool ThoiGian::operator<=(const ThoiGian& tg) {
    return TinhGiay() <= tg.TinhGiay();
}

// Toan tu so sanh >
bool ThoiGian::operator>(const ThoiGian& tg) {
    return TinhGiay() > tg.TinhGiay();
}

// Toan tu so sanh <
bool ThoiGian::operator<(const ThoiGian& tg) {
    return TinhGiay() < tg.TinhGiay();
}

// Toan tu nhap >>
istream& operator>>(istream& is, ThoiGian& tg) {
    cout << "Nhap gio: ";
    is >> tg.iGio;
    cout << "Nhap phut: ";
    is >> tg.iPhut;
    cout << "Nhap giay: ";
    is >> tg.iGiay;
    return is;
}

// Toan tu xuat <<
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << " gio, " << tg.iPhut << " phut, " << tg.iGiay << " giay";
    return os;
}
