// main.cpp
#include <iostream>
#include "DaGiac.h"

int main() {
    DaGiac daGiac;

    std::cout << "Nhap da giac:\n";
    daGiac.Nhap();

    std::cout << "\nDa giac ban dau:\n";
    daGiac.Xuat();

    daGiac.Quay(30);
    std::cout << "\nSau khi quay 30 do:\n";
    daGiac.Xuat();

    daGiac.TinhTien(3, 3);
    daGiac.Xuat();
    return 0;
}
