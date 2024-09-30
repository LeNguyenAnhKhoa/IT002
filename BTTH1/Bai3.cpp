#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    void nhap() {
    /// Enter the numerator and denominator
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) {
            cout << "Mau so khong the bang 0\n";
            nhap();
        }
    }
    void xuat() {
    /// print the fraction
        cout << tu << "/" << mau;
    }
    PhanSo cong(PhanSo ps) {
    /*
        Perform subtraction between two fractions
        Parameters
        ----------
        tu_so: int
            The numerator of the first fraction
        mau_so:int
            The denominator of the first fraction
        ps:    PhanSo
            The second fraction

        Returns
        kq:    PhanSo
            Sum of 2 fractions
    */
        PhanSo kq;
        kq.tu = tu * ps.mau + ps.tu * mau;
        kq.mau = mau * ps.mau;
        return kq;
    }
    PhanSo tru(PhanSo ps) {
    /*
        Perform subtraction between two fractions
        Parameters
        ----------
        tu_so: int
            The numerator of the first fraction
        mau_so:int
            The denominator of the first fraction
        ps:    PhanSo
            The second fraction

        Returns
        kq:    PhanSo
            Difference of 2 fractions
    */
        PhanSo kq;
        kq.tu = tu * ps.mau - ps.tu * mau;
        kq.mau = mau * ps.mau;
        return kq;
    }
    PhanSo nhan(PhanSo ps) {
    /*
        Perform Product of 2 fractions
        Parameters
        ----------
        tu_so: int
            The numerator of the first fraction
        mau_so:int
            The denominator of the first fraction
        ps:    PhanSo
            The second fraction

        Returns
        kq:    PhanSo
            Product of 2 fractions
    */
        PhanSo kq;
        kq.tu = tu * ps.tu;
        kq.mau = mau * ps.mau;
        return kq;
    }
    PhanSo chia(PhanSo ps) {
    /*
        Perform division of 2 fractions
        Parameters
        ----------
        tu_so: int
            The numerator of the first fraction
        mau_so:int
            The denominator of the first fraction
        ps:    PhanSo
            The second fraction

        Returns
        kq:    PhanSo
            Quotient of 2 fractions
    */
        if (ps.tu == 0) {
            cout << "Khong the chia cho 0. Tra ve 0/1.\n";
            return PhanSo();
        }
        PhanSo kq;
        kq.tu = tu * ps.mau;
        kq.mau = mau * ps.tu;
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2, kq;
    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();
    cout << "\nKet qua:\n";
    
    cout << "Tong: ";
    kq = ps1.cong(ps2);
    kq.xuat();
    cout << endl;
    
    cout << "Hieu: ";
    kq = ps1.tru(ps2);
    kq.xuat();
    cout << endl;
    
    cout << "Tich: ";
    kq = ps1.nhan(ps2);
    kq.xuat();
    cout << endl;
    
    cout << "Thuong: ";
    kq = ps1.chia(ps2);
    kq.xuat();
    cout << endl;
    return 0;
}
