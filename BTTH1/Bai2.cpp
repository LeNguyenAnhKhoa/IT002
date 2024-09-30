#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() : tu(0), mau(1) {}
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
    
    int getTu(){
    /*
        Returns
        tu:  int 
            the numerator
    */    
        return tu;
    }

    PhanSo operator-(const PhanSo& ps) const {
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
}PS1, PS2, Hieu;

int main() {
    PS1.nhap();
    PS2.nhap();
    Hieu = PS1 - PS2;
    if(Hieu.getTu() < 0)PS2.xuat();
    else PS1.xuat();
    return 0;
}
