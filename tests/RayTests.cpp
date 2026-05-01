#include <gtest/gtest.h>
#include "core/Ray.hpp"

TEST(RayTest, Constructor) {
    Vec3 origin(0.0f, 0.0f, 0.0f);
    Vec3 direction(1.0f, 0.0f, 0.0f);
    Ray r(origin, direction);
    EXPECT_TRUE(r.getOrigin() == origin);
    EXPECT_TRUE(r.getDirection() == direction);
}

TEST(RayTest, DirectionIsNormalized) {
    Vec3 origin(0.0f, 0.0f, 0.0f);
    Vec3 direction(2.0f, 0.0f, 0.0f);
    Ray r(origin, direction);
    EXPECT_NEAR(r.getDirection().magnitude(), 1.0f, 1e-5f);
}

TEST(RayTest, AtZero) {
    Vec3 origin(1.0f, 2.0f, 3.0f);
    Vec3 direction(1.0f, 0.0f, 0.0f);
    Ray r(origin, direction);
    Vec3 result = r.at(0.0f);
    EXPECT_TRUE(result == origin);
}

TEST(RayTest, AtOne) {
    Vec3 origin(0.0f, 0.0f, 0.0f);
    Vec3 direction(1.0f, 0.0f, 0.0f);
    Ray r(origin, direction);
    Vec3 result = r.at(1.0f);
    EXPECT_NEAR(result.getX(), 1.0f, 1e-5f);
    EXPECT_NEAR(result.getY(), 0.0f, 1e-5f);
    EXPECT_NEAR(result.getZ(), 0.0f, 1e-5f);
}