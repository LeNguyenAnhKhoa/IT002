// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "ThiSinh.h"

int main() {
    int n;
    std::cout << "Nhap so luong thi sinh: ";
    std::cin >> n;
    std::cin.ignore(); // Clear the input buffer

    std::vector<ThiSinh> danhSachThiSinh(n);

    // Input candidates
    for (int i = 0; i < n; ++i) {
        std::cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        danhSachThiSinh[i].Nhap();
    }

    // Print candidates with total score > 15
    std::cout << "\nThi sinh co tong diem lon hon 15:\n";
    for (const auto& thiSinh : danhSachThiSinh) {
        if (thiSinh.getTong() > 15) {
            thiSinh.Xuat();
            std::cout << "------------------------\n";
        }
    }

    // Find candidate with highest score
    auto maxScoreCandidate = std::max_element(danhSachThiSinh.begin(), danhSachThiSinh.end(),
        [](const ThiSinh& a, const ThiSinh& b) {
            return a.getTong() < b.getTong();
        });

    std::cout << "\nThi sinh co diem cao nhat:\n";
    maxScoreCandidate->Xuat();

    return 0;
}
