// point.h
#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;

public:
    // Constructor: Initializes a point with given x and y coordinates
    // Input: x - x-coordinate, y - y-coordinate
    // Output: None
    Point(double x = 0, double y = 0);

    // Doubles both x and y coordinates of the point
    // Input: None
    // Output: None
    void doubleCoordinates();

    // Resets the point to the origin (0, 0)
    // Input: None
    // Output: None
    void resetToOrigin();

    // Translates the point along x or y axis
    // Input: k - direction (0 for x-axis, non-zero for y-axis), d - distance to translate
    // Output: None
    void translate(int k, double d);

    // Prints the point in the format (x, y)
    // Input: None
    // Output: None (prints to console)
    void print() const;
};

#endif // POINT_H
