#include <bits/stdc++.h>
using namespace std;

// Lop PhanSo de bieu dien cac phan so
class PhanSo {
public:
    int tuSo, mauSo;

    // Ham khoi tao
    PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau) {}

    // Ham tinh tich cua 2 phan so
    PhanSo tich(const PhanSo& ps) const {
        return PhanSo(tuSo * ps.tuSo, mauSo * ps.mauSo);
    }

    // So sanh 2 phan so bang nhau (khong can rut gon)
    bool bang(const PhanSo& ps) const {
        return tuSo * ps.mauSo == mauSo * ps.tuSo;
    }

    // Ham in phan so
    void in() const {
        cout << tuSo << "/" << mauSo;
    }

    // Ham so sanh de sap xep phan so theo thu tu tu be den lon
    bool operator<(const PhanSo& ps) const {
        return tuSo * ps.mauSo < mauSo * ps.tuSo;
    }
};

// Lop bai toan tim tap hop con
class TapHopPhanSo {
private:
    vector<PhanSo> cacPhanSo;
    PhanSo phanSoDich;

    // Ham de quay lui tim tap hop con
    void timTapHopCon(int index, PhanSo tichHienTai, vector<PhanSo>& tapHop, vector<PhanSo>& tapHopToiUu, int& soPhanTuItNhat) {
        if (index == cacPhanSo.size()) {
            if (tichHienTai.bang(phanSoDich) && tapHop.size() < soPhanTuItNhat) {
                tapHopToiUu = tapHop;
                soPhanTuItNhat = tapHop.size();
            }
            return;
        }

        // Truong hop khong chon phan so hien tai
        timTapHopCon(index + 1, tichHienTai, tapHop, tapHopToiUu, soPhanTuItNhat);

        // Truong hop chon phan so hien tai
        tapHop.push_back(cacPhanSo[index]);
        PhanSo tichMoi = tichHienTai.tich(cacPhanSo[index]);
        timTapHopCon(index + 1, tichMoi, tapHop, tapHopToiUu, soPhanTuItNhat);
        tapHop.pop_back();  // Quay lui
    }

public:
    // Ham khoi tao
    TapHopPhanSo(vector<PhanSo> phanSo, PhanSo dich) : cacPhanSo(phanSo), phanSoDich(dich) {}

    // Ham tim tap hop con nho nhat co tich bang phan so dich
    vector<PhanSo> timTapHopConToiUu() {
        vector<PhanSo> tapHopToiUu;
        vector<PhanSo> tapHop;
        int soPhanTuItNhat = INT_MAX;

        PhanSo tichHienTai(1, 1);  // Tich ban dau bang 1/1
        timTapHopCon(0, tichHienTai, tapHop, tapHopToiUu, soPhanTuItNhat);

        return tapHopToiUu;
    }

    // Ham sap xep va in ra tap hop con
    void inKetQua(const vector<PhanSo>& tapHop) {
        if (tapHop.empty()) {
            cout << "Khong co tap hop con nao thoa man\n";
        } else {
            vector<PhanSo> ketQua = tapHop;
            sort(ketQua.begin(), ketQua.end());

            for (const PhanSo& ps : ketQua) {
                ps.in();
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> cacPhanSo;
    cout << "Nhap cac phan so (tu so va mau so cach nhau boi dau cach):\n";
    for (int i = 0; i < n; ++i) {
        int tu, mau;
        cin >> tu >> mau;
        cacPhanSo.push_back(PhanSo(tu, mau));
    }

    int a_k, b_k;
    cout << "Nhap phan so dich (tu so va mau so): ";
    cin >> a_k >> b_k;

    PhanSo dich(a_k, b_k);

    // Tao doi tuong TapHopPhanSo
    TapHopPhanSo tapHop(cacPhanSo, dich);

    // Tim tap hop con toi uu
    vector<PhanSo> ketQua = tapHop.timTapHopConToiUu();

    // In ket qua
    tapHop.inKetQua(ketQua);

    return 0;
}
