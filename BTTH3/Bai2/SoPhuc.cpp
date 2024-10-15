#include "SoPhuc.h"

// Constructor mac dinh
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

// Constructor co tham so
SoPhuc::SoPhuc(int thuc, int ao) : dThuc(thuc), dAo(ao) {}

// Toan tu cong
SoPhuc SoPhuc::operator+(const SoPhuc& sp) {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

// Toan tu tru
SoPhuc SoPhuc::operator-(const SoPhuc& sp) {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

// Toan tu nhan
SoPhuc SoPhuc::operator*(const SoPhuc& sp) {
    int thuc = dThuc * sp.dThuc - dAo * sp.dAo;
    int ao = dThuc * sp.dAo + dAo * sp.dThuc;
    return SoPhuc(thuc, ao);
}

// Toan tu chia
SoPhuc SoPhuc::operator/(const SoPhuc& sp) {
    int mau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    int thuc = (dThuc * sp.dThuc + dAo * sp.dAo) / mau;
    int ao = (dAo * sp.dThuc - dThuc * sp.dAo) / mau;
    return SoPhuc(thuc, ao);
}

// Toan tu ==
bool SoPhuc::operator==(const SoPhuc& sp) {
    return (dThuc == sp.dThuc) && (dAo == sp.dAo);
}

// Toan tu !=
bool SoPhuc::operator!=(const SoPhuc& sp) {
    return !(*this == sp);
}

// Toan tu nhap >>
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}

// Toan tu xuat <<
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + " << sp.dAo << "i";
    return os;
}
