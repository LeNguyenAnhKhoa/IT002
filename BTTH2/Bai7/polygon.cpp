#include "polygon.h"
#include <cmath>

Polygon::Polygon() {}

void Polygon::addVertex(double x, double y) {
    vertices.emplace_back(x, y);
}

double Polygon::calculateArea() const {
    double area = 0.0;
    size_t n = vertices.size();

    for (size_t i = 0; i < n; ++i) {
        size_t j = (i + 1) % n;
        area += (vertices[i].getX() * vertices[j].getY() - vertices[j].getX() * vertices[i].getY());
    }

    return std::abs(area) / 2.0;
}

size_t Polygon::getVertexCount() const {
    return vertices.size();
}
