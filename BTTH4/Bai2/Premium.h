#ifndef PREMIUM_H
#define PREMIUM_H

#include "Room.h"

class Premium : public Room {
private:
    double phiDichVu;

public:
    /*
    Ham khoi tao Premium
    Input: so phong, so dem, phi dich vu
    Output: doi tuong Premium
    */
    Premium(int soPhong, int soDem, double phiDichVu);

    /*
    Ham tinh doanh thu phong Premium
    Output: doanh thu = So dem * 500000 + Phi dich vu
    */
    double tinhDoanhThu() override;
};

#endif
