#include "CurveFactory.h"

#include <memory>
#include <random>
#include <vector>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

std::vector<std::shared_ptr<Curve>>
CurveFactory::createRandomCurves(int count) {
    std::vector<std::shared_ptr<Curve>> curves;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0); // Радиус от 1 до 10
    std::uniform_real_distribution<double> step_dist(0.5,
                                                     5.0); // Шаг от 0.5 до 5

    for (int i = 0; i < count; i++) {
        int type = gen() % 3;
        double r = dist(gen);
        switch (type) {
            case 0:
                curves.push_back(std::make_shared<Circle>(r));
                break;
            case 1:
                curves.push_back(std::make_shared<Ellipse>(r, dist(gen)));
                break;
            case 2:
                curves.push_back(std::make_shared<Helix>(r, step_dist(gen)));
                break;
        }
    }
    return curves;
}
