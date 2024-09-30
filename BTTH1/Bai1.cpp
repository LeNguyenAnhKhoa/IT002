#include <bits/stdc++.h>
using namespace std;

struct PS{
    int tu_so, mau_so;
    void rut_gon(){
    /*
        Reduce fractions
        Parameters
        ----------
        tu_so: int
            The numerator of the reduced fraction
        mau_so:int
            The denominator of the reduced fraction    
    */
        if(mau_so == 0){
            cout << "phan so khong ton tai";
            exit(0);
        }
        int gcd = __gcd(tu_so, mau_so);
        tu_so /= gcd;
        mau_so /= gcd;
    }
}phan_so;

int main(){
    cout << "Nhap tu so: ";
    cin >> phan_so.tu_so;
    cout << "Nhap mau so: ";
    cin >> phan_so.mau_so;
    phan_so.rut_gon();
    cout << "Tu so: " << phan_so.tu_so << endl;
    cout << "Mau so: " << phan_so.mau_so << endl;
    return 0;
}
