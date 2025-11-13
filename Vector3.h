#pragma once
#include <iostream>

class Vector3
{
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3 operator*(double scalar) const;
    double x() const { return this->x_; }
    double y() const { return this->y_; }
    double z() const { return this->z_; }
private:
    double x_;
    double y_;
    double z_;
};
