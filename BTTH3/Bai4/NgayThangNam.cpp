#include "NgayThangNam.h"

// Constructor mac dinh
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

// Constructor tham so
NgayThangNam::NgayThangNam(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) {}

// Phuong thuc tinh tong so ngay tinh tu nam 0
int NgayThangNam::TinhNgay() const {
    int tongNgay = iNgay + iThang * 30 + iNam * 365;
    return tongNgay;
}

// Operator + them ngay
NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam kq = *this;
    kq.iNgay += ngay;
    // Dieu chinh ngay, thang, nam neu can thiet (bai toan co the mo rong o day)
    return kq;
}

// Operator - tru ngay
NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam kq = *this;
    kq.iNgay -= ngay;
    // Dieu chinh ngay, thang, nam neu can thiet
    return kq;
}

// Operator tru hai doi tuong NgayThangNam
int NgayThangNam::operator-(const NgayThangNam& a) {
    return this->TinhNgay() - a.TinhNgay();
}

// Operator ++ (tang 1 ngay)
NgayThangNam& NgayThangNam::operator++() {
    ++iNgay;
    // Dieu chinh ngay, thang, nam neu can thiet
    return *this;
}

// Operator -- (giam 1 ngay)
NgayThangNam& NgayThangNam::operator--() {
    --iNgay;
    // Dieu chinh ngay, thang, nam neu can thiet
    return *this;
}

// Operator == so sanh
bool NgayThangNam::operator==(const NgayThangNam& a) {
    return (iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
}

// Operator != so sanh
bool NgayThangNam::operator!=(const NgayThangNam& a) {
    return !(*this == a);
}

// Operator >= so sanh
bool NgayThangNam::operator>=(const NgayThangNam& a) {
    return this->TinhNgay() >= a.TinhNgay();
}

// Operator <= so sanh
bool NgayThangNam::operator<=(const NgayThangNam& a) {
    return this->TinhNgay() <= a.TinhNgay();
}

// Operator > so sanh
bool NgayThangNam::operator>(const NgayThangNam& a) {
    return this->TinhNgay() > a.TinhNgay();
}

// Operator < so sanh
bool NgayThangNam::operator<(const NgayThangNam& a) {
    return this->TinhNgay() < a.TinhNgay();
}

// Nhap tu ban phim
istream& operator>>(istream& is, NgayThangNam& a) {
    cout << "Nhap ngay: ";
    is >> a.iNgay;
    cout << "Nhap thang: ";
    is >> a.iThang;
    cout << "Nhap nam: ";
    is >> a.iNam;
    return is;
}

// Xuat ra man hinh
ostream& operator<<(ostream& os, const NgayThangNam& a) {
    os << a.iNgay << "/" << a.iThang << "/" << a.iNam;
    return os;
}
