#include "SoPhuc.h"

int main() {
    SoPhuc sp1, sp2, sp3;

    // Nhap so phuc thu nhat
    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    // Nhap so phuc thu hai
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    // Phep cong
    sp3 = sp1 + sp2;
    cout << "Tong: " << sp3 << endl;

    // Phep tru
    sp3 = sp1 - sp2;
    cout << "Hieu: " << sp3 << endl;

    // Phep nhan
    sp3 = sp1 * sp2;
    cout << "Tich: " << sp3 << endl;

    // Phep chia
    sp3 = sp1 / sp2;
    cout << "Thuong: " << sp3 << endl;

    // So sanh bang
    if (sp1 == sp2)
        cout << "Hai so phuc bang nhau\n";
    else
        cout << "Hai so phuc khong bang nhau\n";

    return 0;
}
