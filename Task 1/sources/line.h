#ifndef LINE_H
#define LINE_H

#include "curve.h"

class Line : public Curve
{
private:
    Point originPoint;
    Vector2d direction;

public:
    Line();
    Line(Point point, Vector2d direction);

    Point getPoint(double t) const override;
    Vector2d getFirstDerivative(double t) const override;

    Point getOriginPoint() const;
    Vector2d getDirection() const;
};

#endif // LINE_H
