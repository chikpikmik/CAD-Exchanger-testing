#ifndef CURVE_FACTORY_H
#define CURVE_FACTORY_H

#include <memory>
#include <vector>

#include "Curve.h"
class CurveFactory {
  public:
    static std::vector<std::shared_ptr<Curve>> createRandomCurves(int count);
};

#endif
