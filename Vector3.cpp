#include "Vector3.h"

std::ostream& operator<<(std::ostream& os, const Vector3& vector)
{
	os << "Vector3(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ")\n";
	return os;
}

Vector3::Vector3()
{
	x_ = 0;
	y_ = 0;
	z_ = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

Vector3 Vector3::operator*(double scalar) const
{
	// return A * t
	return Vector3(x_ * scalar, y_ * scalar, z_ * scalar);
}

Vector3 Vector3::operator+(const Vector3& vector) const
{
	// return A + B
	return Vector3(x_ + vector.x(), y_ + vector.y(), z_ + vector.z());
}
