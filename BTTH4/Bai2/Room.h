#ifndef ROOM_H
#define ROOM_H

class Room {
protected:
    int soPhong;
    int soDem;
    double doanhThu;

public:
    /*
    Ham khoi tao Room
    Input: so phong, so dem
    Output: doi tuong Room
    */
    Room(int soPhong, int soDem);

    /*
    Ham tinh doanh thu phong
    Output: doanh thu
    */
    virtual double tinhDoanhThu() = 0;

    /*
    Ham lay doanh thu phong
    Output: doanh thu
    */
    double getDoanhThu() const;
};

#endif
