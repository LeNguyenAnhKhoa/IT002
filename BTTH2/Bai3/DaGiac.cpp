// DaGiac.cpp
#include "DaGiac.h"
#include <iostream>

DaGiac::DaGiac() : n(0), Dinh(nullptr) {}

DaGiac::~DaGiac() {
    delete[] Dinh;
}

void DaGiac::Nhap() {
    std::cout << "Nhap so dinh cua da giac: ";
    std::cin >> n;

    delete[] Dinh;
    Dinh = new Diem[n];

    for (int i = 0; i < n; i++) {
        double x, y;
        std::cout << "Nhap toa do dinh " << i+1 << " (x y): ";
        std::cin >> x >> y;
        Dinh[i].setToaDo(x, y);
    }
}

void DaGiac::Xuat() const {
    std::cout << "Da giac voi " << n << " dinh:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Dinh " << i+1 << ": ";
        Dinh[i].xuat();
        std::cout << std::endl;
    }
}

void DaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        Dinh[i].tinhTien(dx, dy);
    }
}

void DaGiac::PhongTo(double factor) {
    for (int i = 1; i < n; i++) {
        Dinh[i].phongTo(factor);
    }
}

void DaGiac::ThuNho(double factor) {
    PhongTo(1.0 / factor);
}

void DaGiac::Quay(double angle) {
    Diem center = Dinh[0];
    for (int i = 1; i < n; i++) {
        Dinh[i].tinhTien(-center.getX(), -center.getY());
        Dinh[i].quay(angle);
        Dinh[i].tinhTien(center.getX(), center.getY());
    }
}
