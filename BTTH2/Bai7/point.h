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

    // Get x coordinate
    // Input: None
    // Output: x coordinate as double
    double getX() const;

    // Get y coordinate
    // Input: None
    // Output: y coordinate as double
    double getY() const;

    // Set x coordinate
    // Input: new x coordinate as double
    // Output: None
    void setX(double x);

    // Set y coordinate
    // Input: new y coordinate as double
    // Output: None
    void setY(double y);
};

#endif // POINT_H
