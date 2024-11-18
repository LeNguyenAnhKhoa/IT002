#include "Room.h"

Room::Room(int soPhong, int soDem) {
    this->soPhong = soPhong;
    this->soDem = soDem;
    this->doanhThu = 0;
}

double Room::getDoanhThu() const {
    return doanhThu;
}
