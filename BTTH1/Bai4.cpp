#include <bits/stdc++.h>
using namespace std;
double x, S = 0, fac[10], n = 3;
int main(){
    std::cin >> x, fac[0] = 1;
    for(int i = 1; i <= 7; ++i)
        fac[i] = fac[i-1] * i;
    for(double i = 0; i <= n; i = i + 1)
        S=S+pow(-1, i)*pow(x, 2*i+1)/fac[int(2*i+1)];
    std::cout << "S = "<< fixed << setprecision(6)<<S;
}
