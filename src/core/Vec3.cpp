#include "Vec3.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>

Vec3 Vec3::zero() {
    return Vec3(0, 0, 0);
}

Vec3 Vec3::up() {
    return Vec3(0, 1, 0);
}

Vec3 Vec3::right() {
    return Vec3(1, 0, 0);
}

Vec3 Vec3::forward() {
    return Vec3(0, 0, 1);
}

Vec3 Vec3::operator+(const Vec3 &other) const {
    float i = x + other.x;
    float j = y + other.y;
    float k = z + other.z;

    return Vec3(i, j, k);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    float i = x - other.x;
    float j = y - other.y;
    float k = z - other.z;

    return Vec3(i, j, k);
}

Vec3 Vec3::operator*(const Vec3 &other) const {
    float i = x * other.x;
    float j = y * other.y;
    float k = z * other.z;
    
    return Vec3(i, j, k);
}

Vec3 Vec3::operator*(float scalar) const {
    float i = x * scalar;
    float j = y * scalar;
    float k = z * scalar;

    return Vec3(i, j, k);
}

Vec3 Vec3::operator/(const Vec3 &other) const {
    if(std::abs(other.x) < 1e-6f ||
       std::abs(other.y) < 1e-6f ||
       std::abs(other.z) < 1e-6f) {
        throw std::invalid_argument("Division by zero!!!");
    }

    float i = x / other.x;
    float j = y / other.y;
    float k = z / other.z;

    return Vec3(i, j, k);
}

bool Vec3::operator==(const Vec3 &other) const {
    return std::abs(x - other.x) < 1e-6f &&
           std::abs(y - other.y) < 1e-6f &&
           std::abs(z - other.z) < 1e-6f;
}

float Vec3::magnitude() const{
    float xSq = x * x;
    float ySq = y * y;
    float zSq = z * z;

    float mag = std::sqrt(xSq + ySq + zSq);

    return mag;
}

Vec3 Vec3::normalized() const {
    float mag = magnitude();
    if(mag < 1e-6f) {
        return Vec3();
    }

    float x1 = x/mag;
    float y1 = y/mag;
    float z1 = z/mag;

    return Vec3(x1, y1, z1);
}

float Vec3::dotProduct(const Vec3 &other) const {
    float xProd = x * other.x;
    float yProd = y * other.y;
    float zProd = z * other.z;

    return xProd + yProd + zProd;
}

Vec3 Vec3::crossProduct(const Vec3 &other) const {
    float xComp = y * other.z - z * other.y;
    float yComp = z * other.x - x * other.z;
    float zComp = x * other.y - y * other.x;

    return Vec3(xComp, yComp, zComp);
}

float Vec3::getX() const{
    return x;
}

float Vec3::getY() const {
    return y;
}

float Vec3::getZ() const {
    return z;
}

std::string Vec3::toString() const {
    std::stringstream ss;
    ss << "(" << x <<"i, " << y << "j, " << z << "k)" << std::endl;
    return ss.str();
}