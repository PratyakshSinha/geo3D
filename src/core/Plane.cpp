#include "Plane.hpp"
#include <sstream>
#include <iostream>

float Plane::distanceFromPlane(const Vec3& point) const {
    float distance = m_normal.dotProduct(point) + m_distance;
    return distance;
}

PlaneSide Plane::checkPoint(const Vec3& point) const {
    auto res = distanceFromPlane(point);

    if(std::abs(res) < 1e-6f) return PlaneSide::OnPlane;
    if(res > 0) {
        return PlaneSide::Front;
    }
    return PlaneSide::Back;
}

float Plane::rayPlaneIntersection(const Ray& r) const {
    float num = -(m_normal.dotProduct(r.getOrigin()) + m_distance);
    float den = m_normal.dotProduct(r.getDirection());

    if(std::abs(den) < 1e-6f) {
        return -1.0f;
    }

    float t = num/den;
    if(t < 0) {
        return -1.0f;
    }

    return t;
}

std::string Plane::toString() const {
    std::stringstream ss;
    ss << "Plane(normal: " << m_normal.toString() << ", distance: " << m_distance;
    return ss.str();
}

void Plane::print() const {
    std::cout << toString();
}