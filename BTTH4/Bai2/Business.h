#ifndef BUSINESS_H
#define BUSINESS_H

#include "Room.h"

class Business : public Room {
public:
    /*
    Ham khoi tao Business
    Input: so phong, so dem
    Output: doi tuong Business
    */
    Business(int soPhong, int soDem);

    /*
    Ham tinh doanh thu phong Business
    Output: doanh thu = So dem * 300000
    */
    double tinhDoanhThu() override;
};

#endif
