#include "NgayThangNam.h"

int main() {
    NgayThangNam nt1, nt2, nt3;

    // Nhap ngay thang nam thu nhat
    cout << "Nhap ngay thang nam thu nhat:\n";
    cin >> nt1;

    // Nhap ngay thang nam thu hai
    cout << "Nhap ngay thang nam thu hai:\n";
    cin >> nt2;

    // Phep cong ngay
    nt3 = nt1 + 5;
    cout << "nt1 + 5 ngay: " << nt3 << endl;

    // Phep tru ngay
    nt3 = nt1 - 10;
    cout << "nt1 - 10 ngay: " << nt3 << endl;

    // Phep tru hai doi tuong
    int soNgayChenhLech = nt1 - nt2;
    cout << "Chenh lech giua nt1 va nt2: " << soNgayChenhLech << " ngay" << endl;

    // Tang giam 1 ngay
    ++nt1;
    cout << "Sau khi ++nt1: " << nt1 << endl;

    --nt2;
    cout << "Sau khi nt2--: " << nt2 << endl;

    // So sanh
    cout << "nt1 == nt2: " << (nt1 == nt2) << endl;
    cout << "nt1 != nt2: " << (nt1 != nt2) << endl;
    cout << "nt1 > nt2: " << (nt1 > nt2) << endl;
    cout << "nt1 < nt2: " << (nt1 < nt2) << endl;
    cout << "nt1 >= nt2: " << (nt1 >= nt2) << endl;
    cout << "nt1 <= nt2: " << (nt1 <= nt2) << endl;

    return 0;
}
