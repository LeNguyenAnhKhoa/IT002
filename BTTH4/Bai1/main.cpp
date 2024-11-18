#include <iostream>
#include "QuanLy.h"
#include "KySu.h"

using namespace std;

/*
* Nhap thong tin quan ly
* Output: doi tuong QuanLy voi thong tin da nhap
*/
QuanLy nhapQuanLy() {
    string maSo, ten;
    double luongCoBan, tyLeThuong;

    cout << "Nhap thong tin Quan ly:" << endl;
    cout << "Ma so: "; getline(cin, maSo);
    cout << "Ten: "; getline(cin, ten);
    cout << "Luong co ban: "; cin >> luongCoBan;
    cout << "Ty le thuong: "; cin >> tyLeThuong;
    cin.ignore();

    return QuanLy(maSo, ten, luongCoBan, tyLeThuong);
}

/*
* Nhap thong tin ky su
* Output: doi tuong KySu voi thong tin da nhap
*/
KySu nhapKySu() {
    string maSo, ten;
    double luongCoBan;
    int soGioLamThem;

    cout << "\nNhap thong tin Ky su:" << endl;
    cout << "Ma so: "; getline(cin, maSo);
    cout << "Ten: "; getline(cin, ten);
    cout << "Luong co ban: "; cin >> luongCoBan;
    cout << "So gio lam them: "; cin >> soGioLamThem;
    cin.ignore();

    return KySu(maSo, ten, luongCoBan, soGioLamThem);
}

int main() {
    QuanLy ql = nhapQuanLy();
    KySu ks = nhapKySu();

    cout << "\nThong tin Quan ly:" << endl;
    ql.xuat();

    cout << "\nThong tin Ky su:" << endl;
    ks.xuat();

    return 0;
}
