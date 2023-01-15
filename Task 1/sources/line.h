#ifndef LINE_H
#define LINE_H

#include "curve.h"

class Line : public Curve
{
private:
    double x0;
    double y0;

    double xD;
    double yD;

public:
    Line();
    Line(double x0, double y0, double xD, double yD);
    double getX(double t) const override;
    double getY(double t) const override;
    double getFirstDerivative(double t) const override;
    std::string getName() const override;

    double getX1() const override;
    double getY1() const override;
    double getX2() const override;
    double getY2() const override;
};

#endif // LINE_H
