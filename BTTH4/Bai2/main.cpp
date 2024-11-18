#include <iostream>
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"
using namespace std;

int main() {
    // Khoi tao cac phong
    Premium a(205, 4, 300000);
    Business b(308, 3);
    Deluxe c(104, 5, 400000, 150000);
    Premium d(207, 2, 200000);
    Business e(102, 4);

    // Tinh doanh thu cho tung phong
    double doanhThuDeluxe = a.tinhDoanhThu() + b.tinhDoanhThu();
    double doanhThuPremium = c.tinhDoanhThu() + d.tinhDoanhThu();
    double doanhThuBusiness = e.tinhDoanhThu();

    cout << "Doanh thu Deluxe: " << doanhThuDeluxe << endl;
    cout << "Doanh thu Premium: " << doanhThuPremium << endl;
    cout << "Doanh thu Business: " << doanhThuBusiness << endl;

    // Tim loai phong co doanh thu cao nhat
    if (doanhThuDeluxe > doanhThuPremium && doanhThuDeluxe > doanhThuBusiness) {
        cout << "Phong Deluxe co doanh thu cao nhat" << endl;
    } else if (doanhThuPremium > doanhThuDeluxe && doanhThuPremium > doanhThuBusiness) {
        cout << "Phong Premium co doanh thu cao nhat" << endl;
    } else {
        cout << "Phong Business co doanh thu cao nhat" << endl;
    }

    return 0;
}
