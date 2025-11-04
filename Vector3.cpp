#include "Vector3.h"

std::ostream& operator<<(std::ostream& os, const Vector3& vector)
{
	os << vector.x << " " << vector.y << " " << vector.z;
	return os;
}

Vector3 Vector3::operator*(double scalar) const 
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}
