#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
//#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define FOD(i, r, l) for(int i = r; i >= l; --i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define push emplace
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
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
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

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

    if (!mangPhanSo.empty()) {
        PhanSo minPhanSo = mangPhanSo[0];
        PhanSo maxPhanSo = mangPhanSo[0];

        for (const auto& ps : mangPhanSo) {
            if (ps < minPhanSo) {
                minPhanSo = ps;
            }
            if (ps > maxPhanSo) {
                maxPhanSo = ps;
            }
        }

        cout << "Phan so nho nhat: ";
        minPhanSo.hienThi();
        cout << endl;
        cout << "Phan so lon nhat: ";
        maxPhanSo.hienThi();
        cout << endl;
    } else {
        cout << "Khong co phan so nao duoc nhap." << endl;
    }

    return 0;
}
