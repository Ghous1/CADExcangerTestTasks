#include <iostream>
#include <vector>
#include "line.h"
#include "ellipse.h"
#include "randomnumber.h"

void randomN(std::vector <Curve*> *curves);
double randomNum();

int main()
{
    std::vector <Curve*> curves;
    curves.resize(0);

    randomN(&curves);

    const double PI = acos(-1.0);
    double t = PI / 4;

    for (size_t i = 0; i < curves.size(); i++) {
        std::cout << "Type: " << curves[i]->getName();
        if (curves[i]->getName() == Line().getName()) {
            std::cout << " Origin point: ( " << curves[i]->getX1() << ", " << curves[i]->getY1() << ")"
                      << " Direction: ( " << curves[i]->getX2() << ", " << curves[i]->getY2() << ")";
        } else {
            std::cout << " First radi: ( " << curves[i]->getX1() << ", " << curves[i]->getY2() << ")" << ", ( " << curves[i]->getX1() << ", " << curves[i]->getY1() << ")"
                      << " Second radi: ( " << curves[i]->getX1() << ", " << curves[i]->getY2() << ")" << ", ( " << curves[i]->getX2() << ", " << curves[i]->getY2() << ")";
        }
        std::cout << "\nX = " << curves[i]->getX(t)
                  << ", Y = " << curves[i]->getY(t) << ", first derivative = "
                  << curves[i]->getFirstDerivative(t) << "\n\n";
    }

    _getwch();
}

void randomN(std::vector <Curve*> *curves) {
    RandomNumber rnd;
    size_t size = rnd.uniformRandom(10, 20);

    for (size_t i = 0; i < size; i++) {
        if (rnd.uniformRandom(0, 1)) {
            curves->push_back(new Line(randomNum(), randomNum(), randomNum(), randomNum()));
        } else {
            curves->push_back(new Ellipse(randomNum(), randomNum(), randomNum(), randomNum()));
        }
    }
}

double randomNum() {
    RandomNumber rnd;
    const double min = -20.0;
    const double max = 20.0;
    return rnd.doubleUniformRandom(min, max);
}
