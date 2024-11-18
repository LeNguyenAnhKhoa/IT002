#include "QuanLy.h"
#include <iostream>

/*
* Constructor tao quan ly moi
* Input: ma so, ten, luong co ban, ty le thuong
* Output: doi tuong QuanLy
*/
QuanLy::QuanLy(string maSo, string ten, double luongCoBan, double tyLeThuong)
    : NhanVien(maSo, ten, luongCoBan) {
    this->tyLeThuong = tyLeThuong;
}

// Getter/Setter
double QuanLy::getTyLeThuong() const { return tyLeThuong; }
void QuanLy::setTyLeThuong(double tyLeThuong) { this->tyLeThuong = tyLeThuong; }

/*
* Tinh tien thuong cho quan ly
* Output: so tien thuong = luong co ban * ty le thuong
*/
double QuanLy::tienThuong() const {
    return luongCoBan * tyLeThuong;
}

/*
* Xuat thong tin quan ly
* Output: hien thi thong tin quan ly bao gom tien thuong
*/
void QuanLy::xuat() const {
    NhanVien::xuat();
    cout << "Ty le thuong: " << tyLeThuong << endl;
    cout << "Tien thuong: " << tienThuong() << endl;
}
