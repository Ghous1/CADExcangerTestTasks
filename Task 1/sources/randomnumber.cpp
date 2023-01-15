#include "randomnumber.h"
#include "time.h"
RandomNumber::RandomNumber()
{
    std::random_device rd;
    gen = new std::mt19937(rd());
}

double RandomNumber::expRandom(double lambda)
{
    std::exponential_distribution<double> expDis(lambda);
    return expDis(*gen);
}

int RandomNumber::uniformRandom(int low, int high)
{
    std::uniform_int_distribution<int> uniformDis(low, high);
    return uniformDis(*gen);
}

double RandomNumber::doubleUniformRandom(double low, double high)
{
    std::uniform_real_distribution<double> uniformRealDis(low, high);
    return uniformRealDis(*gen);
}




