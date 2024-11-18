#include "Premium.h"

Premium::Premium(int soPhong, int soDem, double phiDichVu)
    : Room(soPhong, soDem) {
    this->phiDichVu = phiDichVu;
}

double Premium::tinhDoanhThu() {
    doanhThu = soDem * 500000 + phiDichVu;
    return doanhThu;
}
