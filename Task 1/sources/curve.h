#ifndef CURVE_H
#define CURVE_H
#include <cmath>
#include <string>
#include "point.h"
#include "vector2d.h"

class Curve
{
public:
    Curve();
    virtual ~Curve();
    virtual Point getPoint(double t) const = 0;
    virtual Vector2d getFirstDerivative(double t) const = 0;
};

#endif // CURVE_H
