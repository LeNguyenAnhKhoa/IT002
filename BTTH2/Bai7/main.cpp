#include <iostream>
#include "polygon.h"

int main() {
    int n;
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    if (n <= 2) {
        std::cout << "Error: The number of vertices must be greater than 2." << std::endl;
        return 1;
    }

    Polygon polygon;

    std::cout << "Enter the coordinates of " << n << " vertices:" << std::endl;
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        polygon.addVertex(x, y);
    }

    double area = polygon.calculateArea();
    std::cout << "The area of the polygon is: " << area << std::endl;

    return 0;
}
