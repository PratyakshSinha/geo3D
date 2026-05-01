#include "Ray.hpp"
#include <sstream>
#include <iostream>

Ray::Ray(const Vec3& origin, const Vec3& direction){
    m_origin = origin;
    m_direction = direction.normalized();
}

Vec3 Ray::at(float t) const {
    Vec3 result;
    result = m_origin + t * m_direction;
    return result;
}

std::string Ray::toString() const {
    std::stringstream ss;
    ss << "Origin: " << m_origin.toString() << "Direction: " << m_direction.toString();
    return ss.str();
}

void Ray::print() const {
    std::cout << toString() << std::endl;
}

Vec3 Ray::getOrigin() const {
    return m_origin;
}

Vec3 Ray::getDirection() const {
    return m_direction;
}