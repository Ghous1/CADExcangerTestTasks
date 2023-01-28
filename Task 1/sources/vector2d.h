#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2d {
    double x;
    double y;

    Vector2d() {}
    Vector2d(double x, double y)
        : x(x), y(y)
    {}
};

#endif // VECTOR2D_H
