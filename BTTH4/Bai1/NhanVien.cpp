#include "NhanVien.h"
#include <iostream>

/*
* Constructor tao nhan vien moi
* Input: ma so, ten, luong co ban
* Output: doi tuong NhanVien
*/
NhanVien::NhanVien(string maSo, string ten, double luongCoBan) {
    this->maSo = maSo;
    this->ten = ten;
    this->luongCoBan = luongCoBan;
}

// Cac ham getter
string NhanVien::getMaSo() const { return maSo; }
string NhanVien::getTen() const { return ten; }
double NhanVien::getLuongCoBan() const { return luongCoBan; }

// Cac ham setter
void NhanVien::setMaSo(string maSo) { this->maSo = maSo; }
void NhanVien::setTen(string ten) { this->ten = ten; }
void NhanVien::setLuongCoBan(double luongCoBan) { this->luongCoBan = luongCoBan; }

/*
* Xuat thong tin nhan vien
* Output: hien thi thong tin co ban cua nhan vien
*/
void NhanVien::xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
}
