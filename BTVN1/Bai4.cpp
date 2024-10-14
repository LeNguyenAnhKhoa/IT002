#include <bits/stdc++.h>
using namespace std;

class ArnoldsCatMap {
private:
    int m; // kich thuoc cua ma tran
    vector<vector<int>> matrix; // ma tran ban dau
    vector<vector<int>> originalMatrix; // ma tran goc dung de so sanh
public:
    // Ham khoi tao voi kich thuoc ma tran va ma tran du lieu
    ArnoldsCatMap(int size, vector<vector<int>>& mat) {
        m = size;
        matrix = mat;
        originalMatrix = mat; // luu tru lai trang thai ban dau
    }

    // Ham ap dung phep bien doi Arnold's Cat Map
    void applyCatMap() {
        vector<vector<int>> newMatrix(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                // Ap dung cong thuc bien doi Arnold's Cat Map
                int newX = (2 * i + j) % m;
                int newY = (i + j) % m;
                newMatrix[newX][newY] = matrix[i][j];
            }
        }
        matrix = newMatrix; // Cap nhat ma tran sau khi bien doi
    }

    // Ham kiem tra xem ma tran hien tai co tro lai trang thai ban dau khong
    bool isOriginal() {
        return matrix == originalMatrix;
    }

    // Ham tinh he so chu ky k (so lan bien doi can thiet de tro lai trang thai ban dau)
    int findCycle() {
        int cycle = 0;
        do {
            applyCatMap();
            cycle++;
        } while (!isOriginal()); // lap lai cho den khi tro ve trang thai ban dau
        return cycle;
    }

    // Ham in ma tran (phuc vu viec kiem tra, khong can thiet cho chuong trinh chinh)
    void printMatrix() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> m;

    vector<vector<int>> mat(m, vector<int>(m));
    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    ArnoldsCatMap acm(m, mat); // Khoi tao doi tuong Arnold's Cat Map voi ma tran

    int cycle = acm.findCycle(); // Tim he so chu ky
    cout << "He so chu ky k la: " << cycle << endl;

    return 0;
}
