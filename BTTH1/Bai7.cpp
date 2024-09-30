#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// Class representing a student
class HocSinh {
private:
    string hoTen;        // Full name
    float diemToan;      // Math score
    float diemVan;       // Literature score
    float diemNgoaiNgu;  // Foreign language score
    float diemTrungBinh; // Average score
    string xepLoai;      // Classification

public:
    // Constructor
    // Input: Full name, Math score, Literature score, Foreign language score
    // Output: A new HocSinh object
    HocSinh(string ht, float dt, float dv, float dnn) :
        hoTen(ht), diemToan(dt), diemVan(dv), diemNgoaiNgu(dnn) {
        tinhDiemTrungBinh();
        xepLoaiHocSinh();
    }

    // Calculate average score
    // Input: None (uses member variables)
    // Output: None (updates diemTrungBinh)
    void tinhDiemTrungBinh() {
        diemTrungBinh = (2 * diemToan + diemVan + diemNgoaiNgu) / 4;
    }

    // Classify student based on average score
    // Input: None (uses diemTrungBinh)
    // Output: None (updates xepLoai)
    void xepLoaiHocSinh() {
        if (diemTrungBinh >= 9) xepLoai = "Xuat sac";      // Excellent
        else if (diemTrungBinh >= 8) xepLoai = "Gioi";     // Very good
        else if (diemTrungBinh >= 6.5) xepLoai = "Kha";    // Good
        else if (diemTrungBinh >= 5) xepLoai = "Trung binh"; // Average
        else xepLoai = "Yeu ";                              // Poor
    }

    // Getter methods
    // Input: None
    // Output: Respective member variable values
    string getHoTen() const { return hoTen; }
    float getDiemToan() const { return diemToan; }
    float getDiemVan() const { return diemVan; }
    float getDiemNgoaiNgu() const { return diemNgoaiNgu; }
    float getDiemTrungBinh() const { return diemTrungBinh; }
    string getXepLoai() const { return xepLoai; }
};

// Validate student's name
// Input: string hoTen (student's full name)
// Output: bool (true if valid, false otherwise)
bool kiemTraHoTen(const string& hoTen) {
    if (hoTen.empty() || hoTen.length() > 50) return false;

    bool hasLetter = false;
    for (char c : hoTen) {
        if (isdigit(c)) return false;
        if (isalpha(c)) hasLetter = true;
    }
    return hasLetter;
}

// Input score for a subject
// Input: string monHoc (subject name)
// Output: float (valid score between 0 and 10)
float nhapDiem(const string& monHoc) {
    float diem;
    do {
        cout << "Enter " << monHoc << " score (0-10): ";
        cin >> diem;
        if (cin.fail() || diem < 0 || diem > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid score. Please try again.\n";
        } else {
            break;
        }
    } while (true);
    return diem;
}

// Input information for multiple students
// Input: vector<HocSinh>& danhSachHocSinh (reference to vector of students)
// Output: None (modifies danhSachHocSinh)
void nhapThongTin(vector<HocSinh>& danhSachHocSinh) {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter information for student " << i + 1 << ":\n";
        string hoTen;
        do {
            cout << "Full name: ";
            getline(cin, hoTen);
            if (!kiemTraHoTen(hoTen)) {
                cout << "Invalid name. Please enter a name with only letters and spaces.\n";
            }
        } while (!kiemTraHoTen(hoTen));

        float diemToan = nhapDiem("Math");
        float diemVan = nhapDiem("Literature");
        float diemNgoaiNgu = nhapDiem("Foreign Language");

        danhSachHocSinh.emplace_back(hoTen, diemToan, diemVan, diemNgoaiNgu);
    }
}

// Display student information
// Input: const HocSinh& hs (reference to a student object)
// Output: None (prints student information to console)
void xuatThongTin(const HocSinh& hs) {
    cout << "Full name: " << hs.getHoTen() << endl;
    cout << "Math score: " << hs.getDiemToan() << endl;
    cout << "Literature score: " << hs.getDiemVan() << endl;
    cout << "Foreign Language score: " << hs.getDiemNgoaiNgu() << endl;
    cout << "Average score: " << fixed << setprecision(2) << hs.getDiemTrungBinh() << endl;
    cout << "Classification: " << hs.getXepLoai() << endl;
}

// Find student with highest average score
// Input: const vector<HocSinh>& danhSachHocSinh (reference to vector of students)
// Output: None (prints information of student with highest average score)
void timHocSinhDiemCaoNhat(const vector<HocSinh>& danhSachHocSinh) {
    if (danhSachHocSinh.empty()) {
        cout << "Student list is empty.\n";
        return;
    }

    auto it = max_element(danhSachHocSinh.begin(), danhSachHocSinh.end(),
        [](const HocSinh& a, const HocSinh& b) {
            return a.getDiemTrungBinh() < b.getDiemTrungBinh();
        });

    cout << "\nStudent with the highest average score:\n";
    xuatThongTin(*it);
}

// Search for students by name
// Input: const vector<HocSinh>& danhSachHocSinh (reference to vector of students)
// Output: None (prints information of students matching the search keyword)
void timKiemTheoTen(const vector<HocSinh>& danhSachHocSinh) {
    string tuKhoa;
    cout << "Enter student name to search: ";
    cin.ignore();
    getline(cin, tuKhoa);

    transform(tuKhoa.begin(), tuKhoa.end(), tuKhoa.begin(), ::tolower);

    bool timThay = false;
    for (const auto& hs : danhSachHocSinh) {
        string tenHocSinh = hs.getHoTen();
        transform(tenHocSinh.begin(), tenHocSinh.end(), tenHocSinh.begin(), ::tolower);
        if (tenHocSinh.find(tuKhoa) != string::npos) {
            cout << "\nStudent information:\n";
            xuatThongTin(hs);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "No student found with name containing '" << tuKhoa << "'.\n";
    }
}

// Display list of students with lowest math score
// Input: const vector<HocSinh>& danhSachHocSinh (reference to vector of students)
// Output: None (prints information of students with lowest math score)
void xuatDanhSachDiemToanThapNhat(const vector<HocSinh>& danhSachHocSinh) {
    if (danhSachHocSinh.empty()) {
        cout << "Student list is empty.\n";
        return;
    }

    float diemToanThapNhat = danhSachHocSinh[0].getDiemToan();
    for (const auto& hs : danhSachHocSinh) {
        if (hs.getDiemToan() < diemToanThapNhat) {
            diemToanThapNhat = hs.getDiemToan();
        }
    }

    cout << "\nList of students with lowest math score (" << diemToanThapNhat << "):\n";
    for (const auto& hs : danhSachHocSinh) {
        if (hs.getDiemToan() == diemToanThapNhat) {
            xuatThongTin(hs);
            cout << "-------------------------\n";
        }
    }
}

// Main function
// Input: None
// Output: int (program exit status)
int main() {
    vector<HocSinh> danhSachHocSinh;
    int luaChon;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Input student information\n";
        cout << "2. Find student with highest average score\n";
        cout << "3. Search for students by name\n";
        cout << "4. Display list of students with lowest math score\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> luaChon)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (luaChon) {
            case 1:
                nhapThongTin(danhSachHocSinh);
                break;
            case 2:
                timHocSinhDiemCaoNhat(danhSachHocSinh);
                break;
            case 3:
                timKiemTheoTen(danhSachHocSinh);
                break;
            case 4:
                xuatDanhSachDiemToanThapNhat(danhSachHocSinh);
                break;
            case 0:
                cout << "Thank you for using the program!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (luaChon != 0);

    return 0;
}
