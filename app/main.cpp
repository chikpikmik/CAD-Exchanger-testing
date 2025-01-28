#include <algorithm> //std::sort
#include <cmath>     //M_PI
#include <iostream>
#include <memory>  //std::shared_ptr
#include <numeric> //std::accumulate
#include <vector>  //std::vector

#include "Circle.h"
#include "Curve.h"
#include "CurveFactory.h"
#include "Point3D.h"
#include "Vector3D.h"

int main() {
    // 2. Заполнить контейнер
    auto curves = CurveFactory::createRandomCurves(10);

    // 3. Напечатать координаты точек и производные всех кривых в контейнере при
    // t=PI/4.
    double t = M_PI / 4.0;
    std::cout << "Points and derivatives at t = PI/4:" << std::endl;
    for (const auto &curve : curves) {
        Point3D point = curve->getPoint(t);
        Vector3D derivative = curve->getDerivative(t);
        printf("Point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
        printf("Derivative: (%.2f, %.2f, %.2f)\n", derivative.x, derivative.y,
               derivative.z);
    }

    // 4. Заполнить второй контейнер, который будет содержать только окружности
    // из первого контейнера
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto &curve : curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }

    // 5. Сортировка окружностей по радиусу
    std::sort(
      circles.begin(), circles.end(),
      [](const std::shared_ptr<Circle> &a, const std::shared_ptr<Circle> &b) {
          return a->getRadius() < b->getRadius();
      });

    // 6. Сумма радиусов
    double totalRadius =
      std::accumulate(circles.begin(), circles.end(), 0.0,
                      [](double sum, const std::shared_ptr<Circle> &circle) {
                          return sum + circle->getRadius();
                      });

    std::cout << "Total radius of circles: " << totalRadius << std::endl;

    return 0;
}
