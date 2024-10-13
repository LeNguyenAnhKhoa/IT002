// ThiSinh.h
#ifndef THISINH_H
#define THISINH_H

#include <string>

class ThiSinh {
private:
    std::string Ten;
    std::string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    ThiSinh();

    // Input candidate information
    // Input: None (user input via console)
    // Output: None (modifies object properties)
    void Nhap();

    // Output candidate information
    // Input: None
    // Output: None (prints to console)
    void Xuat() const;

    // Calculate total score
    // Input: None
    // Output: float (sum of fToan, fVan, fAnh)
    float Tong() const;

    // Getter for total score
    float getTong() const;
};

#endif // THISINH_H
