#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x;
    float y;

public:
    // Constructor: Initializes a point with given x and y coordinates
    // Input: x - x-coordinate, y - y-coordinate
    // Output: None
    Point(float x = 0, float y = 0);

    // Get x coordinate
    // Input: None
    // Output: x coordinate as float
    float getX() const;

    // Get y coordinate
    // Input: None
    // Output: y coordinate as float
    float getY() const;

    // Set x coordinate
    // Input: new x coordinate as float
    // Output: None
    void setX(float x);

    // Set y coordinate
    // Input: new y coordinate as float
    // Output: None
    void setY(float y);

    // Translate the point
    // Input: angle - angle in degrees, distance - distance to translate
    // Output: None
    void translate(float angle, float distance);

    // Print the point coordinates
    // Input: None
    // Output: None (prints to console)
    void print() const;
};

#endif // POINT_H
