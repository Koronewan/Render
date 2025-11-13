#include "Vector3.h"

std::ostream& operator<<(std::ostream& os, const Vector3& vector)
{
	os << "Vector3(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ")\n";
	return os;
}

Vector3::Vector3()
{
	this->x_ = 0;
	this->y_ = 0;
	this->z_ = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x_ = x;
	this->y_ = y;
	this->z_ = z;
}

Vector3 Vector3::operator*(double scalar) const
{
	return Vector3(x_ * scalar, y_ * scalar, z_ * scalar);
}
