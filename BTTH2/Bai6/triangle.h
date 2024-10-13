#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle {
private:
    Point p1, p2, p3;

public:
    // Constructor: Initializes a triangle with three points
    // Input: x1, y1, x2, y2, x3, y3 - coordinates of three points
    // Output: None
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3);

    // Translate the triangle
    // Input: angle - angle in degrees, distance - distance to translate
    // Output: None
    void translate(float angle, float distance);

    // Print the triangle coordinates
    // Input: None
    // Output: None (prints to console)
    void print() const;
};

#endif // TRIANGLE_H
