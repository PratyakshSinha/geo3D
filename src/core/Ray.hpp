#pragma once
#include "Vec3.hpp"
#include <string>

class Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction);

    Vec3 at(float t) const;
    std::string toString() const;
    void print() const;

    Vec3 getOrigin() const;
    Vec3 getDirection() const;

private:
    Vec3 m_origin;
    Vec3 m_direction;
};