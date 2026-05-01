#include <gtest/gtest.h>
#include "core/Mat4.hpp"
#include <corecrt_math_defines.h>

TEST(Mat4Test, DefaultIsIdentity) {
    Mat4 m;
    Mat4 identity = Mat4::identity();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(m.get(i,j), identity.get(i,j));
}

TEST(Mat4Test, ScalarMultiply) {
    Mat4 m;
    Mat4 result = m * 2.0f;
    EXPECT_FLOAT_EQ(result.get(0,0), 2.0f);
    EXPECT_FLOAT_EQ(result.get(1,1), 2.0f);
    EXPECT_FLOAT_EQ(result.get(2,2), 2.0f);
    EXPECT_FLOAT_EQ(result.get(3,3), 2.0f);
}

TEST(Mat4Test, MultiplyByIdentity) {
    float src[4][4] = {
        {2, 0, 0, 0},
        {0, 3, 0, 0},
        {0, 0, 4, 0},
        {0, 0, 0, 1}
    };
    Mat4 a(src);
    Mat4 result = a * Mat4::identity();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(result.get(i,j), a.get(i,j));
}

TEST(Mat4Test, Inverse) {
    float src[4][4] = {
        {2, 0, 0, 0},
        {0, 3, 0, 0},
        {0, 0, 4, 0},
        {0, 0, 0, 1}
    };
    Mat4 a(src);
    Mat4 inv = a.inverse();
    Mat4 result = a * inv;
    Mat4 identity = Mat4::identity();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            EXPECT_NEAR(result.get(i,j), identity.get(i,j), 1e-5f);
}

TEST(Mat4Test, Transpose) {
    float src[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Mat4 a(src);
    Mat4 t = a.transpose();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            EXPECT_FLOAT_EQ(t.get(i,j), a.get(j,i));
}

TEST(Mat4Test, TranslationFactory) {
    Mat4 t = Mat4::translation(1.0f, 2.0f, 3.0f);
    Vec3 point(0.0f, 0.0f, 0.0f);
    Vec3 result = t * point;
    EXPECT_FLOAT_EQ(result.getX(), 1.0f);
    EXPECT_FLOAT_EQ(result.getY(), 2.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 3.0f);
}

TEST(Mat4Test, ScaleFactory) {
    Mat4 s = Mat4::scale(2.0f, 3.0f, 4.0f);
    Vec3 point(1.0f, 1.0f, 1.0f);
    Vec3 result = s * point;
    EXPECT_FLOAT_EQ(result.getX(), 2.0f);
    EXPECT_FLOAT_EQ(result.getY(), 3.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 4.0f);
}

TEST(Mat4Test, RotationZ90) {
    Mat4 r = Mat4::rotationZ(M_PI / 2.0f);
    Vec3 point(1.0f, 0.0f, 0.0f);
    Vec3 result = r * point;
    EXPECT_NEAR(result.getX(), 0.0f, 1e-5f);
    EXPECT_NEAR(result.getY(), 1.0f, 1e-5f);
    EXPECT_NEAR(result.getZ(), 0.0f, 1e-5f);
}