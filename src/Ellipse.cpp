#include "Ellipse.h"

#include <cmath>

Ellipse::Ellipse(double radiusX, double radiusY)
    : radiusX(radiusX), radiusY(radiusY) {}

Point3D Ellipse::getPoint(double t) const {
    return {radiusX * cos(t), radiusY * sin(t), 0.0};
}

Vector3D Ellipse::getDerivative(double t) const {
    return {-radiusX * sin(t), radiusY * cos(t), 0.0};
}
