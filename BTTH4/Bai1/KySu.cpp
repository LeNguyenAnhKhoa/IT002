#include "KySu.h"
#include <iostream>

/*
* Constructor tao ky su moi
* Input: ma so, ten, luong co ban, so gio lam them
* Output: doi tuong KySu
*/
KySu::KySu(string maSo, string ten, double luongCoBan, int soGioLamThem)
    : NhanVien(maSo, ten, luongCoBan) {
    this->soGioLamThem = soGioLamThem;
}

// Getter/Setter
int KySu::getSoGioLamThem() const { return soGioLamThem; }
void KySu::setSoGioLamThem(int soGioLamThem) { this->soGioLamThem = soGioLamThem; }

/*
* Tinh tien thuong cho ky su
* Output: so tien thuong = so gio lam them * 100000
*/
double KySu::tienThuong() const {
    return soGioLamThem * 100000;
}

/*
* Xuat thong tin ky su
* Output: hien thi thong tin ky su bao gom tien thuong
*/
void KySu::xuat() const {
    NhanVien::xuat();
    cout << "So gio lam them: " << soGioLamThem << endl;
    cout << "Tien thuong: " << tienThuong() << endl;
}
