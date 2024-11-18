#ifndef KYSU_H
#define KYSU_H

#include "NhanVien.h"

class KySu : public NhanVien {
private:
    int soGioLamThem;

public:
    // Constructor
    KySu(string maSo = "", string ten = "", double luongCoBan = 0, int soGioLamThem = 0);

    // Getter/Setter
    int getSoGioLamThem() const;
    void setSoGioLamThem(int soGioLamThem);

    // Tinh tien thuong
    double tienThuong() const override;

    // Xuat thong tin
    void xuat() const override;
};

#endif
