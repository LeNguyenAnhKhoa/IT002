#ifndef DELUXE_H
#define DELUXE_H

#include "Room.h"

class Deluxe : public Room {
private:
    double phiDichVu;
    double phiPhucVu;

public:
    /*
    Ham khoi tao Deluxe
    Input: so phong, so dem, phi dich vu, phi phuc vu
    Output: doi tuong Deluxe
    */
    Deluxe(int soPhong, int soDem, double phiDichVu, double phiPhucVu);

    /*
    Ham tinh doanh thu phong Deluxe
    Output: doanh thu = So dem * 750000 + Phi dich vu + Phi phuc vu
    */
    double tinhDoanhThu() override;
};

#endif
