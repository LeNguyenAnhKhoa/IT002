#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
protected:
    string maSo;
    string ten;
    double luongCoBan;

public:
    // Constructor
    NhanVien(string maSo = "", string ten = "", double luongCoBan = 0);

    // Getter/Setter
    string getMaSo() const;
    string getTen() const;
    double getLuongCoBan() const;

    void setMaSo(string maSo);
    void setTen(string ten);
    void setLuongCoBan(double luongCoBan);

    // Phuong thuc tinh tien thuong - ham ao thuan tuy
    virtual double tienThuong() const = 0;

    // Phuong thuc xuat thong tin
    virtual void xuat() const;
};

#endif
