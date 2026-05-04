#pragma once

#include "Mat4.hpp"
#include "Ray.hpp"

class Shape
{

public:
    virtual float intersect(const Ray &r) const = 0;
    virtual Vec3 getNormal(const Vec3 &v) const = 0;

    Mat4 getTransform() const { return m_transform; }
    void setTransform(const Mat4 &t) { m_transform = t; }

    virtual ~Shape() = default;

protected:
    Mat4 m_transform;
};