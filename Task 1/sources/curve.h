#ifndef CURVE_H
#define CURVE_H
#include <cmath>
#include <string>
class Curve
{
public:
    Curve();
    virtual ~Curve();
    virtual double getX(double t) const = 0;
    virtual double getY(double t) const = 0;
    virtual double getFirstDerivative(double t) const = 0;
    virtual std::string getName() const = 0;

    virtual double getX1() const = 0;
    virtual double getY1() const = 0;
    virtual double getX2() const = 0;
    virtual double getY2() const = 0;
};

#endif // CURVE_H
