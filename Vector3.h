#pragma once
#include <iostream>

class Vector3
{
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
public:
    Vector3() : x(0), y(0), z(0) { };
    Vector3(double x, double y, double z) : x(x), y(y), z(z) { };
    Vector3 operator*(double scalar) const;
private:
    double x;
    double y;
    double z;
};
