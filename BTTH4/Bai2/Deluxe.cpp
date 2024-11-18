#include "Deluxe.h"

Deluxe::Deluxe(int soPhong, int soDem, double phiDichVu, double phiPhucVu)
    : Room(soPhong, soDem) {
    this->phiDichVu = phiDichVu;
    this->phiPhucVu = phiPhucVu;
}

double Deluxe::tinhDoanhThu() {
    doanhThu = soDem * 750000 + phiDichVu + phiPhucVu;
    return doanhThu;
}
