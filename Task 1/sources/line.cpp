#include "line.h"

Line::Line()
{
    x0 = 0;
    y0 = 0;
    xD = 0;
    yD = 0;
}

Line::Line(double x0, double y0, double xD, double yD)
{
    this->x0 = x0;
    this->y0 = y0;
    this->xD = xD;
    this->yD = yD;
}

double Line::getX(double t) const {
    return xD * t + x0;
}

double Line::getY(double t) const {
    return yD * t + y0;
}

double Line::getFirstDerivative(double t) const {
    return yD / xD;
}

std::string Line::getName() const {
    return "Line";
}

double Line::getX1() const {
    return x0;
}

double Line::getY1() const {
    return y0;
}

double Line::getX2() const {
    return xD;
}

double Line::getY2() const {
    return yD;
}
