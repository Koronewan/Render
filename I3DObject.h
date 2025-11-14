#pragma once
#include "Ray.h"

class I3DObject
{
public:
    virtual ~I3DObject() {}
    virtual bool hit(const Ray& r) const = 0;
};
