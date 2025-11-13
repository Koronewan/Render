#pragma once
#include "Vector3.h"

class Ray
{
	Ray(const Vector3& origin, const Vector3& direction);
	Vector3 point_at_parameter(double t) const;
	inline Vector3 origin() const { return origin_; };
	inline Vector3 direction() const { return direction_; };
private:
	Vector3 origin_;
	Vector3 direction_;
};

