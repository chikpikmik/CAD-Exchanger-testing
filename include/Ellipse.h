#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve.h"

class Ellipse : public Curve {
  private:
    double radiusX;
    double radiusY;

  public:
    Ellipse(double radiusX, double radiusY);
    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
};

#endif
