#include <gtest\gtest.h>
#include <iostream>
#include <Plane.h>

using std::cout;
using std::endl;
using GravityBind::Plane;
using GravityBind::Vector3;

TEST(PlaneTests, ConstructorTest) {
	Vector3 normal(0, 1, 0);
	Plane plane(normal, Vector3::zero());

	EXPECT_TRUE(plane.normal == normal);
	EXPECT_TRUE(plane.point == Vector3::zero());

	cout << plane << endl;
}

TEST(PlaneTests, IsInsideTest) {
	Vector3 normal(0, 1, 0);

	Vector3 inside(313, 0, 0);
	Vector3 outside(0, 1, 0);

	Plane plane(normal, Vector3::zero());

	EXPECT_TRUE(plane.isInside(Vector3::zero()));
	EXPECT_TRUE(plane.isInside(inside));
	//EXPECT_TRUE(plane.isInside(outside));

	cout << plane << endl;
}