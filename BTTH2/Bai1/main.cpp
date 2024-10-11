#include <iostream>
#include "Diem.h"

using namespace std;

int main() {
    // Create a point using the default constructor
    Diem point1;
    point1.Xuat(); // Output the coordinates of point1

    // Create a point using the parameterized constructor
    Diem point2(5, 10);
    point2.Xuat(); // Output the coordinates of point2

    // Create a point using the copy constructor
    Diem point3(point2);
    point3.Xuat(); // Output the coordinates of point3

    // Change the coordinates of point3
    point3.SetHoanhDo(15);
    point3.SetTungDo(20);
    point3.Xuat(); // Output the updated coordinates of point3

    // Translate point3 by (3, -4)
    point3.TinhTien(3, -4);
    point3.Xuat(); // Output the new coordinates of point3 after translation

    // Get and print the coordinates of point2
    cout << "Point2 coordinates: (" << point2.GetHoanhDo() << ", " << point2.GetTungDo() << ")" << endl;

    return 0;
}
