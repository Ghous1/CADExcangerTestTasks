#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class Ellipse : public Curve
{
private:
    Point centerPoint;

    double radiusX;
    double radiusY;

public:
    Ellipse();
    Ellipse(Point point, double radius1, double radius2);

    Point getPoint(double t) const override;
    Vector2d getFirstDerivative(double t) const override;

    Point getCenter() const;

    double getR1() const;
    double getR2() const;
};

#endif // ELLIPSE_H
