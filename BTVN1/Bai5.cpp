#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Lop dai dien cho hinh chu nhat
class Rectangle {
public:
    int x, y, w, h;  // Toa do goc (x, y) va chieu rong w, chieu cao h

    Rectangle(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}

    // Ham de in thong tin hinh chu nhat
    void print() const {
        cout << "[" << x << ", " << y << ", " << w << ", " << h << "]" << endl;
    }

    // Ham so sanh de sap xep cac hinh chu nhat theo thu tu tu trai sang phai, tu tren xuong duoi
    bool operator<(const Rectangle& other) const {
        if (y != other.y)
            return y < other.y;
        return x < other.x;
    }
};

// Lop dai dien cho anh nhi phan va tim kiem hinh chu nhat
class BinaryImage {
private:
    int m, n;
    vector<vector<int>> matrix;
    vector<Rectangle> rectangles;

    // Kiem tra xem co phai la mot hinh chu nhat hop le tu (startX, startY) hay khong
    bool isValidRectangle(int startX, int startY, int endX, int endY) {
        for (int i = startY; i <= endY; ++i) {
            for (int j = startX; j <= endX; ++j) {
                if (matrix[i][j] == 1) return false;
            }
        }
        return true;
    }

    // Tim cac hinh chu nhat tu toa do (i, j)
    void findRectangle(int i, int j) {
        int maxW = 0, maxH = 0;

        // Tim chieu rong lon nhat co the tai vi tri (i, j)
        for (int x = j; x < n && matrix[i][x] == 0; ++x) {
            maxW = x - j + 1;
            // Tim chieu cao lon nhat co the cho chieu rong da tim duoc
            for (int y = i; y < m && matrix[y][j] == 0; ++y) {
                if (isValidRectangle(j, i, j + maxW - 1, y)) {
                    maxH = y - i + 1;
                    // Neu tim duoc hinh chu nhat >= 2x2, them vao danh sach
                    if (maxW >= 2 && maxH >= 2) {
                        rectangles.push_back(Rectangle(j, i, maxW, maxH));
                    }
                }
            }
        }

        // Danh dau tat ca phan tu cua hinh chu nhat thanh 1 de tranh xet lai
        for (int y = i; y < i + maxH; ++y) {
            for (int x = j; x < j + maxW; ++x) {
                matrix[y][x] = 1;
            }
        }
    }

public:
    // Ham khoi tao ma tran
    BinaryImage(int _m, int _n, const vector<vector<int>>& _matrix) : m(_m), n(_n), matrix(_matrix) {}

    // Tim va luu tat ca cac hinh chu nhat
    void findAllRectangles() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    findRectangle(i, j);
                }
            }
        }
    }

    // In danh sach cac hinh chu nhat da tim duoc
    void printRectangles() {
        sort(rectangles.begin(), rectangles.end());
        for (const auto& rect : rectangles) {
            rect.print();
        }
    }
};

int main() {
    int m, n;
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Nhap ma tran (0 hoac 1):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tao doi tuong BinaryImage va tim cac hinh chu nhat
    BinaryImage image(m, n, matrix);
    image.findAllRectangles();

    // In ket qua
    cout << "Danh sach cac hinh chu nhat:" << endl;
    image.printRectangles();

    return 0;
}
