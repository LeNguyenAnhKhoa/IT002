#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    /**
     * Constructor
     * @param tu: tu so cua phan so
     * @param mau: mau so cua phan so, khong duoc bang 0
     * @throws invalid_argument neu mau so bang 0
     */
    PhanSo(int tu, int mau) {
        if (mau == 0) {
            throw invalid_argument("Mau so phai khac 0");
        }
        tuSo = tu;
        mauSo = mau;
    }

    /**
     * Tinh gia tri cua phan so
     * @return gia tri thuc cua phan so
     */
    double giaTri() const {
        return static_cast<double>(tuSo) / mauSo;
    }

    /**
     * Hien thi phan so
     * Hien thi tu so va mau so cua phan so theo dinh dang tuSo/mauSo
     */
    void hienThi() const {
        cout << tuSo << "/" << mauSo;
    }

    /**
     * Toan tu so sanh nho hon
     * @param ps: phan so de so sanh
     * @return true neu phan so hien tai nho hon phan so ps, nguoc lai false
     */
    bool operator<(const PhanSo& ps) const {
        return this->giaTri() < ps.giaTri();
    }

    /**
     * Toan tu so sanh lon hon
     * @param ps: phan so de so sanh
     * @return true neu phan so hien tai lon hon phan so ps, nguoc lai false
     */
    bool operator>(const PhanSo& ps) const {
        return this->giaTri() > ps.giaTri();
    }
};

int main() {
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << "Nhap gia tri k: ";
    cin >> k;

    vector<PhanSo> mangPhanSo;
    for (int i = 0; i < n; ++i) {
        int tu, mau;
        cout << "Nhap tu so va mau so cua phan so thu " << i + 1 << ": ";
        cin >> tu >> mau;
        while (mau == 0) {
            cout << "Mau so phai khac 0. Nhap lai mau so: ";
            cin >> mau;
        }
        try {
            PhanSo ps(tu, mau);
            mangPhanSo.push_back(ps);
        } catch (invalid_argument& e) {
            cout << e.what() << endl;
            --i;
        }
    }

    if (mangPhanSo.size() >= k) {
        sort(mangPhanSo.begin(), mangPhanSo.end());

        cout << "Phan so be thu " << k << ": ";
        mangPhanSo[k - 1].hienThi();
        cout << endl;

        cout << "Phan so lon thu " << k << ": ";
        mangPhanSo[mangPhanSo.size() - k].hienThi();
        cout << endl;
    } else {
        cout << "Khong co phan so lon thu " << k << " hoac be thu " << k << endl;
    }

    return 0;
}
