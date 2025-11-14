#pragma once
#include "I3DObject.h"

class Sphere : I3DObject
{
public:
	Sphere(double radius, const Vector3& position);
	bool hit(const Ray& r) const override;
private:
	double radius_;
	Vector3 position_;
};

