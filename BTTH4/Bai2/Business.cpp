#include "Business.h"

Business::Business(int soPhong, int soDem)
    : Room(soPhong, soDem) {
}

double Business::tinhDoanhThu() {
    doanhThu = soDem * 300000;
    return doanhThu;
}
