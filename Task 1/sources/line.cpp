#include "line.h"

Line::Line()
{
    originPoint.x = 0;
    originPoint.y = 0;
    direction.x = 1;
    direction.y = 1;
}

Line::Line(Point point, Vector2d direction)
    :originPoint(point), direction(direction)
{
}

Point Line::getPoint(double t) const
{
    Point point((direction.x * t + originPoint.x),
                (direction.y * t + originPoint.y));
    return point;
}

Vector2d Line::getFirstDerivative(double t) const
{
    Vector2d firstDerivative(direction.x, direction.y);
    return firstDerivative;
}

Point Line::getOriginPoint() const
{
    return originPoint;
}

Vector2d Line::getDirection() const
{
    return direction;
}
