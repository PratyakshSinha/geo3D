#include <gtest/gtest.h>
#include "core/Plane.hpp"

TEST(PlaneTest, constructor) {
    Vec3 normal(1,2,3);
    float distance = 4;
    Plane p(normal, distance);
    EXPECT_TRUE(p.getNormal() == normal.normalized());
    EXPECT_FLOAT_EQ(p.getDistance(), distance);
}

TEST(PlaneTest, distanceFromPlane) {
    Vec3 normal(1,2,3);
    float distance = 4;
    Plane p(normal, distance);
    Vec3 p1(4,7,5), p2(1,9,8), p3(4,6,3);
    EXPECT_NEAR(p.distanceFromPlane(p1), 12.81958, 1e-4f);
    EXPECT_NEAR(p.distanceFromPlane(p2), 15.49218, 1e-4f);
    EXPECT_NEAR(p.distanceFromPlane(p3), 10.6815, 1e-4f);
}

TEST(PlaneTest, checkPoint) {
    Plane p(Vec3(0,1,0), 0);
    Vec3 p1(0,5,0);
    Vec3 p2(0,-5,0);
    Vec3 p3(0,0,0);
    EXPECT_EQ(PlaneSide::Front, p.checkPoint(p1));
    EXPECT_EQ(PlaneSide::Back, p.checkPoint(p2));
    EXPECT_EQ(PlaneSide::OnPlane, p.checkPoint(p3));
}

TEST(PlaneTest, rayPlaneIntersection) {
    Plane p(Vec3(0,1,0), 0);
    Ray r1(Vec3(0,5,0), Vec3(0,-1,0));
    Ray r2(Vec3(0,5,0), Vec3(1,0,0));
    Ray r3(Vec3(0,5,0), Vec3(0,1,0));
    EXPECT_FLOAT_EQ(p.rayPlaneIntersection(r1), 5.0f);
    EXPECT_FLOAT_EQ(p.rayPlaneIntersection(r2), -1.0f);
    EXPECT_FLOAT_EQ(p.rayPlaneIntersection(r3), -1.0f);
}