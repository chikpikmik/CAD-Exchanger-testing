#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle : public Curve {
  private:
    double radius;

  public:
    Circle(double radius);
    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
    double getRadius() const;
};

#endif
