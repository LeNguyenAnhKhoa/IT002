#include "PhanSo.h"

int main() {
    PhanSo ps1(1, 2);
    PhanSo ps2(3, 4);
    PhanSo ps3;

    cout << "Nhap phan so 1: " << endl;
    cin >> ps1;
    cout << "Phan so 1: " << ps1 << endl;

    cout << "Nhap phan so 2: " << endl;
    cin >> ps2;
    cout << "Phan so 2: " << ps2 << endl;

    cout << "Tong: " << ps1 + ps2 << endl;
    cout << "Hieu: " << ps1 - ps2 << endl;
    cout << "Tich: " << ps1 * ps2 << endl;
    cout << "Thuong: " << ps1 / ps2 << endl;

    cout << "ps1 == ps2: " << (ps1 == ps2) << endl;
    cout << "ps1 != ps2: " << (ps1 != ps2) << endl;
    cout << "ps1 >= ps2: " << (ps1 >= ps2) << endl;
    cout << "ps1 <= ps2: " << (ps1 <= ps2) << endl;
    cout << "ps1 > ps2: " << (ps1 > ps2) << endl;
    cout << "ps1 < ps2: " << (ps1 < ps2) << endl;

    return 0;
}
