#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    double tyLeThuong;

public:
    // Constructor
    QuanLy(string maSo = "", string ten = "", double luongCoBan = 0, double tyLeThuong = 0);

    // Getter/Setter
    double getTyLeThuong() const;
    void setTyLeThuong(double tyLeThuong);

    // Tinh tien thuong
    double tienThuong() const override;

    // Xuat thong tin
    void xuat() const override;
};

#endif
