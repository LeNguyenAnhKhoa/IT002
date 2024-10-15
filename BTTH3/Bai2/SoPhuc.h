#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

using namespace std;

class SoPhuc {
private:
    int dThuc; // Phan thuc
    int dAo;   // Phan ao

public:
    // Constructor mac dinh
    SoPhuc();

    // Constructor co tham so
    SoPhuc(int thuc, int ao);

    // Toan tu + cho phep cong 2 so phuc
    SoPhuc operator+(const SoPhuc& sp);

    // Toan tu - cho phep tru 2 so phuc
    SoPhuc operator-(const SoPhuc& sp);

    // Toan tu * cho phep nhan 2 so phuc
    SoPhuc operator*(const SoPhuc& sp);

    // Toan tu / cho phep chia 2 so phuc
    SoPhuc operator/(const SoPhuc& sp);

    // Toan tu == kiem tra 2 so phuc co bang nhau khong
    bool operator==(const SoPhuc& sp);

    // Toan tu != kiem tra 2 so phuc co khac nhau khong
    bool operator!=(const SoPhuc& sp);

    // Toan tu >> dung de nhap so phuc
    friend istream& operator>>(istream& is, SoPhuc& sp);

    // Toan tu << dung de xuat so phuc
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
};

#endif
