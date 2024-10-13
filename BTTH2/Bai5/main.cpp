// main.cpp
#include <iostream>
#include "point.h"

int main() {
    double x, y;
    std::cout << "Enter x and y coordinates of the point: ";
    std::cin >> x >> y;

    Point point(x, y);

    int n;
    std::cout << "Enter the number of instructions: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int instruction;
        std::cout << "Enter instruction (1, 2, or 3): ";
        std::cin >> instruction;

        switch (instruction) {
            case 1:
                point.doubleCoordinates();
                break;
            case 2:
                point.resetToOrigin();
                break;
            case 3:
                int k;
                double d;
                std::cout << "Enter direction (0 for x-axis, non-zero for y-axis): ";
                std::cin >> k;
                std::cout << "Enter distance to translate: ";
                std::cin >> d;
                point.translate(k, d);
                break;
            default:
                // Do nothing for other instructions
                break;
        }
    }

    std::cout << "Final point coordinates: ";
    point.print();

    return 0;
}
