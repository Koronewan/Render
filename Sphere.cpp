#include "Sphere.h"

Sphere::Sphere(double radius, const Vector3& position) :
    radius_(radius), position_(position)
{

}

bool Sphere::hit(const Ray& r) const
{
    Vector3 D = r.origin() - position_; // D = A - C
    double a = r.direction().dot(r.direction()); // a = B . B
    double b = r.direction().dot(D) * 2; // b = 2 * B . D
    double c = D.dot(D) - radius_ * radius_; // c = D . D - radius * radius

    // det = b^2 - 4ac must be >= 0 if there's exist at least 1 solution, so 1 collision
    return b * b - 4 * a * c >= 0;
}
