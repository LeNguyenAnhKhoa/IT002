// Point.h
#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0);
    void setCoordinates(double x, double y);
    double getX() const;
    double getY() const;
    void translate(double dx, double dy);
    void scale(double factor);
    void rotate(double angle);
    void print() const;
};

#endif // POINT_H
