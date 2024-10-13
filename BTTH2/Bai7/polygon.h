#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "point.h"

class Polygon {
private:
    std::vector<Point> vertices;

public:
    // Constructor: Initializes an empty polygon
    // Input: None
    // Output: None
    Polygon();

    // Add a vertex to the polygon
    // Input: x - x-coordinate, y - y-coordinate
    // Output: None
    void addVertex(double x, double y);

    // Calculate the area of the polygon
    // Input: None
    // Output: Area of the polygon as double
    double calculateArea() const;

    // Get the number of vertices
    // Input: None
    // Output: Number of vertices as size_t
    size_t getVertexCount() const;
};

#endif // POLYGON_H
