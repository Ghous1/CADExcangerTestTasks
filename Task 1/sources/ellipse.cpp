#include "ellipse.h"
#include "curve.h"

Ellipse::Ellipse()
{
    centerPoint.x = 0;
    centerPoint.y = 0;
    radiusX = 3;
    radiusY = 1;
}

Ellipse::Ellipse(Point point, double radius1, double radius2)
    : centerPoint(point), radiusX(radius1), radiusY(radius2)
{
    if (radiusX < radiusY) std::swap(radiusX, radiusY);
}

Point Ellipse::getPoint(double t) const
{
    Point point;
    point.x = (centerPoint.x * cos(t)) + radiusY;
    point.y = (centerPoint.y * sin(t)) + radiusX;

    return point;
}

Vector2d Ellipse::getFirstDerivative(double t) const
{
    Vector2d result;
    result.x = (radiusX * sin(t));
    result.y = - (radiusY * cos(t));

    return result;
}

Point Ellipse::getCenter() const
{
    return centerPoint;
}


double Ellipse::getR1() const
{
    return radiusX;
}

double Ellipse::getR2() const
{
    return radiusY;
}
