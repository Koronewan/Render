#include "Ray.h"

Ray::Ray(const Vector3& origin, const Vector3& direction) :
    origin_(origin), direction_(direction)
{

}

Vector3 Ray::point_at_parameter(double t) const
{
    // Lineal function y = ax + b
    return origin_ + direction_ * t;
}
