// ThiSinh.cpp
#include "ThiSinh.h"
#include <iostream>
#include <iomanip>

ThiSinh::ThiSinh() : iNgay(0), iThang(0), iNam(0), fToan(0), fVan(0), fAnh(0) {}

void ThiSinh::Nhap() {
    std::cout << "Nhap ten: ";
    std::getline(std::cin, Ten);

    std::cout << "Nhap MSSV: ";
    std::getline(std::cin, MSSV);

    std::cout << "Nhap ngay sinh (ngay thang nam): ";
    std::cin >> iNgay >> iThang >> iNam;

    std::cout << "Nhap diem Toan: ";
    std::cin >> fToan;

    std::cout << "Nhap diem Van: ";
    std::cin >> fVan;

    std::cout << "Nhap diem Anh: ";
    std::cin >> fAnh;

    std::cin.ignore(); // Clear the input buffer
}

void ThiSinh::Xuat() const {
    std::cout << "Ten: " << Ten << std::endl;
    std::cout << "MSSV: " << MSSV << std::endl;
    std::cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << std::endl;
    std::cout << "Diem Toan: " << fToan << std::endl;
    std::cout << "Diem Van: " << fVan << std::endl;
    std::cout << "Diem Anh: " << fAnh << std::endl;
    std::cout << "Tong diem: " << std::fixed << std::setprecision(2) << Tong() << std::endl;
}

float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}

float ThiSinh::getTong() const {
    return Tong();
}
