#include "Helix.h"

#include <cmath>

Helix::Helix(double radius, double step) : radius(radius), step(step) {}

Point3D Helix::getPoint(double t) const {
    return {radius * cos(t), radius * sin(t), step * t / (2 * M_PI)};
}

Vector3D Helix::getDerivative(double t) const {
    return {-radius * sin(t), radius * cos(t), step / (2 * M_PI)};
}
