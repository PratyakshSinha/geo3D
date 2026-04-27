#pragma once
#include <cmath>
#include <string>

class Vec3
{
public:
    Vec3(float a = 0, float b = 0, float c = 0)
    {
        x = a;
        y = b;
        z = c;
    }

    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(const Vec3 &other) const;
    Vec3 operator/(const Vec3 &other) const;
    bool operator==(const Vec3 &other) const;
    float dotProduct(const Vec3 &other) const;
    Vec3 crossProduct(const Vec3 &other) const;

    float magnitude() const;
    Vec3 normalized() const;

    static Vec3 zero();
    static Vec3 up();
    static Vec3 right();
    static Vec3 forward();

    float getX() const;
    float getY() const;
    float getZ() const;
    std::string toString() const;

private:
    float x;
    float y;
    float z;
};
