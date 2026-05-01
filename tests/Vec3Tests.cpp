#include <gtest/gtest.h>
#include "core/Vec3.hpp"

TEST(Vec3Test, DefaultConstructor) {
    Vec3 v;
    EXPECT_FLOAT_EQ(v.getX(), 0.0f);
    EXPECT_FLOAT_EQ(v.getY(), 0.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 0.0f);
}

TEST(Vec3Test, ParameterizedConstructor) {
    Vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v.getX(), 1.0f);
    EXPECT_FLOAT_EQ(v.getY(), 2.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 3.0f);
}

TEST(Vec3Test, Addition) {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);
    Vec3 result = a + b;
    EXPECT_FLOAT_EQ(result.getX(), 5.0f);
    EXPECT_FLOAT_EQ(result.getY(), 7.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 9.0f);
}

TEST(Vec3Test, Subtraction) {
    Vec3 a(4.0f, 5.0f, 6.0f);
    Vec3 b(1.0f, 2.0f, 3.0f);
    Vec3 result = a - b;
    EXPECT_FLOAT_EQ(result.getX(), 3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 3.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 3.0f);
}

TEST(Vec3Test, ScalarMultiply) {
    Vec3 v(1.0f, 2.0f, 3.0f);
    Vec3 result = v * 2.0f;
    EXPECT_FLOAT_EQ(result.getX(), 2.0f);
    EXPECT_FLOAT_EQ(result.getY(), 4.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 6.0f);
}

TEST(Vec3Test, DotProduct) {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);
    EXPECT_FLOAT_EQ(a.dotProduct(b), 32.0f);
}

TEST(Vec3Test, CrossProduct) {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);
    Vec3 result = a.crossProduct(b);
    EXPECT_FLOAT_EQ(result.getX(), -3.0f);
    EXPECT_FLOAT_EQ(result.getY(),  6.0f);
    EXPECT_FLOAT_EQ(result.getZ(), -3.0f);
}

TEST(Vec3Test, Magnitude) {
    Vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_NEAR(v.magnitude(), 3.74166f, 1e-4f);
}

TEST(Vec3Test, Normalized) {
    Vec3 v(1.0f, 0.0f, 0.0f);
    Vec3 result = v.normalized();
    EXPECT_FLOAT_EQ(result.magnitude(), 1.0f);
}

TEST(Vec3Test, EqualityOperator) {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(1.0f, 2.0f, 3.0f);
    EXPECT_TRUE(a == b);
}

TEST(Vec3Test, StaticFactories) {
    EXPECT_TRUE(Vec3::zero()    == Vec3(0.0f, 0.0f, 0.0f));
    EXPECT_TRUE(Vec3::up()      == Vec3(0.0f, 1.0f, 0.0f));
    EXPECT_TRUE(Vec3::right()   == Vec3(1.0f, 0.0f, 0.0f));
    EXPECT_TRUE(Vec3::forward() == Vec3(0.0f, 0.0f, 1.0f));
}