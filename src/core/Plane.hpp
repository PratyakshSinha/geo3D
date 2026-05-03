#pragma once
#include <string>
#include "Vec3.hpp"
#include "Ray.hpp"

enum class PlaneSide{
    Front,
    Back,
    OnPlane
};

class Plane {
public:
    Plane(const Vec3& norm, float d) {
        m_normal = norm.normalized();
        m_distance = d;
    }

    PlaneSide checkPoint(const Vec3& point) const;
    float distanceFromPlane(const Vec3& point) const;
    float rayPlaneIntersection(const Ray& r) const;

    std::string toString() const;
    void print() const;

    Vec3 getNormal(){
        return m_normal;
    }

    float getDistance(){
        return m_distance;
    }

private:
    Vec3 m_normal;
    float m_distance;
};