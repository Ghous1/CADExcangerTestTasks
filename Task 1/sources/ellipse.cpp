#include "ellipse.h"
#include "curve.h"

Ellipse::Ellipse()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

Ellipse::Ellipse(double x1, double y1, double x2, double y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

double Ellipse::getX(double t) const {
    return ((x1 - x2) * cos(t)) + x2;
}

double Ellipse::getY(double t) const {
    return ((y2 - y1) * cos(t)) + y1;
}

double Ellipse::getFirstDerivative(double t) const {
  return -(y2 * cos(t)) / (x1 * sin(t));
}

std::string Ellipse::getName() const {
    return "Ellipse";
}

double Ellipse::getX1() const {
    return x1;
}

double Ellipse::getY1() const {
    return y1;
}

double Ellipse::getX2() const {
    return x2;
}

double Ellipse::getY2() const {
    return y2;
}
