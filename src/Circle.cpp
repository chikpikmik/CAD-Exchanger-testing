#include "Circle.h"

#include <cmath>

Circle::Circle(double radius) : radius(radius) {}

Point3D Circle::getPoint(double t) const {
    return {radius * cos(t), radius * sin(t), 0.0};
}

Vector3D Circle::getDerivative(double t) const {
    return {-radius * sin(t), radius * cos(t), 0.0};
}

double Circle::getRadius() const { return radius; }
