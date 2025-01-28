#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"

class Helix : public Curve {
  private:
    double radius;
    double step;

  public:
    Helix(double radius, double step);
    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
};

#endif
