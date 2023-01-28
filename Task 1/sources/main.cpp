#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <typeinfo>
#include "line.h"
#include "ellipse.h"
#include "point.h"
#include "randomnumber.h"

void addCurves(std::vector <std::unique_ptr<Curve>> &curves);
void printResult(std::vector <std::unique_ptr<Curve>> &curves, double t);
double randomNum();

int main()
{
    std::vector <std::unique_ptr<Curve>> curves;
    const double t = M_PI / 4;

    addCurves(curves);
    printResult(curves, t);

    _getwch();
}

void printResult(std::vector <std::unique_ptr<Curve>> &curves, double t)
{
    for (size_t i = 0; i < curves.size(); i++) {
        if (dynamic_cast <Line*> (&*curves[i]) != nullptr) {
            std::cout << "Line" << std::endl;
            Line& temp = dynamic_cast <Line&> (*curves[i]);
            const Point point = temp.getOriginPoint();
            const Vector2d direction = temp.getDirection();
            std::cout << "  Origin point: (" << point.x << ", " << point.y << ")"
                      << " Direction: (" << direction.x << ", " << direction.y << ")" << std::endl;
        } else {
            std::cout << "Ellipse" << std::endl;
            Ellipse& temp = dynamic_cast <Ellipse&> (*curves[i]);
            const Point point = temp.getCenter();
            std::cout << "  Center point: (" << point.x << ", " << point.y << ")"
                      << " Radii: (" << temp.getR1() << ", " << temp.getR2() << ")" << std::endl;
        }

        const Vector2d temp = curves[i]->getFirstDerivative(t);
        const Point tempPoint = curves[i]->getPoint(t);
        std::cout << "  X = " << tempPoint.x << ", Y = " << tempPoint.y
                  << ", first derivative = " << "(" << temp.x << ", " << temp.y << ")" << std::endl;
    }
}

void addCurves(std::vector <std::unique_ptr<Curve>> &curves)
{
    RandomNumber rnd;
    size_t size = rnd.uniformRandom(10, 20);
    curves.resize(size);
    for (size_t i = 0; i < size; i++) {
        if (rnd.uniformRandom(0, 1)) {
            curves[i] = (std::make_unique<Line>(Point(randomNum(), randomNum()), Vector2d(randomNum(), randomNum())));
        } else {
            curves[i] = (std::make_unique<Ellipse>(Point(randomNum(), randomNum()), fabs(randomNum()), fabs(randomNum())));
        }
    }
}

double randomNum()
{
    RandomNumber rnd;
    const double min = -20.0;
    const double max = 20.0;
    return rnd.doubleUniformRandom(min, max);
}
