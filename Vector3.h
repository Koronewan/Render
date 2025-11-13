#pragma once
#include <iostream>

class Vector3
{
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3 operator*(double scalar) const;
    Vector3 operator+(const Vector3 &vector) const;
    inline double x() const { return x_; }
    inline double y() const { return y_; }
    inline double z() const { return z_; }
private:
    double x_;
    double y_;
    double z_;
};
