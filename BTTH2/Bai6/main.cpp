// main.cpp
#include <iostream>
#include "triangle.h"

int main() {
    float x1, y1, x2, y2, x3, y3;
    float angle, distance;

    // Input triangle coordinates
    std::cout << "Enter the coordinates of three points (x1 y1 x2 y2 x3 y3): ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Create triangle
    Triangle triangle(x1, y1, x2, y2, x3, y3);

    // Print original triangle
    std::cout << "Original ";
    triangle.print();

    // Input translation parameters
    std::cout << "Enter the angle (in degrees) and distance for translation: ";
    std::cin >> angle >> distance;

    // Translate triangle
    triangle.translate(angle, distance);

    // Print translated triangle
    std::cout << "Translated ";
    triangle.print();

    return 0;
}
