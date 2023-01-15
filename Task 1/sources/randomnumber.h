#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
#include <random>

class RandomNumber
{
public:
    RandomNumber();
    double expRandom(double lambda);
    int uniformRandom(int low, int high);
    double doubleUniformRandom(double low, double high);
private:
    std::mt19937* gen;
};

#endif // RANDOMNUMBER_H
