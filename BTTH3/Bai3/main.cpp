#include "ThoiGian.h"

int main() {
    ThoiGian tg1, tg2, tg3;

    // Nhap thoi gian thu nhat
    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;

    // Nhap thoi gian thu hai
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

    // In ket qua phep cong
    tg3 = tg1 + tg2;
    cout << "tg1 + tg2: " << tg3 << endl;

    // In ket qua phep tru
    tg3 = tg1 - tg2;
    cout << "tg1 - tg2: " << tg3 << endl;

    // Kiem tra cac phep ++ (tang len 1 giay) va -- (giam di 1 giay)
    ++tg1;  // Tien to tang tg1
    cout << "Sau khi ++tg1: " << tg1 << endl;

    --tg2;  // Hau to giam tg2
    cout << "Sau khi tg2--: " << tg2 << endl;

    // In ket qua cac phep so sanh
    cout << "tg1 == tg2: " << (tg1 == tg2) << endl;
    cout << "tg1 != tg2: " << (tg1 != tg2) << endl;
    cout << "tg1 > tg2: " << (tg1 > tg2) << endl;
    cout << "tg1 < tg2: " << (tg1 < tg2) << endl;
    cout << "tg1 >= tg2: " << (tg1 >= tg2) << endl;
    cout << "tg1 <= tg2: " << (tg1 <= tg2) << endl;

    return 0;
}
