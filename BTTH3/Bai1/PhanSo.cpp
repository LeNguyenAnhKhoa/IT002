#include "PhanSo.h"
#include <bits/stdc++.h>

PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    if (iMau == 0) {
        cout << "Loi: Mau so khong the bang 0. Dat mac dinh la 1." << endl;
        iMau = 1;
    }
    RutGon();
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    PhanSo result(iTu * other.iMau + other.iTu * iMau, iMau * other.iMau);
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    PhanSo result(iTu * other.iMau - other.iTu * iMau, iMau * other.iMau);
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    PhanSo result(iTu * other.iTu, iMau * other.iMau);
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    if (other.iTu == 0) {
        cout << "Loi: Khong the chia cho 0." << endl;
        return PhanSo();
    }
    PhanSo result(iTu * other.iMau, iMau * other.iTu);
    result.RutGon();
    return result;
}

bool PhanSo::operator==(const PhanSo& other) const {
    return (iTu * other.iMau == other.iTu * iMau);
}

bool PhanSo::operator!=(const PhanSo& other) const {
    return !(*this == other);
}

bool PhanSo::operator>=(const PhanSo& other) const {
    return (iTu * other.iMau >= other.iTu * iMau);
}

bool PhanSo::operator<=(const PhanSo& other) const {
    return (iTu * other.iMau <= other.iTu * iMau);
}

bool PhanSo::operator>(const PhanSo& other) const {
    return (iTu * other.iMau > other.iTu * iMau);
}

bool PhanSo::operator<(const PhanSo& other) const {
    return (iTu * other.iMau < other.iTu * iMau);
}

istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.iTu;
    cout << "Nhap mau so: ";
    is >> ps.iMau;
    if (ps.iMau == 0) {
        cout << "Loi: Mau so khong the bang 0. Dat mac dinh la 1." << endl;
        ps.iMau = 1;
    }
    ps.RutGon();
    return is;
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.iTu << "/" << ps.iMau;
    return os;
}

void PhanSo::RutGon() {
    int gcd = abs(__gcd(iTu, iMau));
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}
