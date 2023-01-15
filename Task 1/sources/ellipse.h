#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class Ellipse : public Curve
{
private:
    double x1;
    double y1;

    double x2;
    double y2;

public:
    Ellipse();
    Ellipse(double x1, double y1, double x2, double y2);
    double getX(double t) const override;
    double getY(double t) const override;
    double getFirstDerivative(double t) const override;
    std::string getName() const override;

    double getX1() const override;
    double getY1() const override;
    double getX2() const override;
    double getY2() const override;
};

#endif // ELLIPSE_H
