#include <gtest\gtest.h>
#include <iostream>
#include <Vector3.h>

using std::cout;
using std::endl;
using GravityBind::Vector3;

TEST(Vector3Tests, ConstructorTest) {
	Vector3 vec;
	Vector3 vecB(1, 2, 3);

	EXPECT_TRUE(vec.x == 0 && vec.y == 0 && vec.z == 0);
	EXPECT_TRUE(vecB.x == 1 && vecB.y == 2 && vecB.z == 3);
}

TEST(Vector3Tests, EqualsTest) {
	Vector3 v;
	Vector3 w(1, 2, 3);
	Vector3 u(1, 2, 3);

	EXPECT_TRUE(w == u && u == w);
	EXPECT_TRUE(v == Vector3::zero());
}

TEST(Vector3Tests, AdditionTest) {
	Vector3 v;
	Vector3 w(1, 2, 3);
	Vector3 u(-6, 7, 10);
	Vector3 t(-5, 9, 13);

	EXPECT_TRUE(v + w == w);
	EXPECT_TRUE(u + w == t);
}

TEST(Vector3Tests, SubTest) {
	Vector3 v;
	Vector3 w(1, 2, 3);
	Vector3 u(-6, 7, 10);
	Vector3 t(-5, 9, 13);

	EXPECT_TRUE(t - u == w);
}

TEST(Vector3Tests, DotTest) {
	Vector3 v;
	Vector3 w(1, 2, 3);
	Vector3 u(2, 3, 5);
	float r = 23;

	EXPECT_TRUE(w * u == r);
	EXPECT_TRUE(w * u == u * w);
}

TEST(Vector3Test, CauchySchwarzTest) {
	Vector3 vec1(2, 3, 8);
	Vector3 vec2(5, 7, 1);
	Vector3 vec3(20, 30, -4);

	EXPECT_TRUE(abs(vec1 * vec2) <= vec1.magnitude() * vec2.magnitude());
	//EXPECT_TRUE(abs(vec1 * vec3) == vec1.magnitude() * vec3.magnitude());
}

TEST(Vector3Test, VectorTriangleInnequality) {
	Vector3 vec1(2, 3, 7);
	Vector3 vec2(5, 7, 0);
	Vector3 vec3(20, -6);

	EXPECT_TRUE((vec1 + vec2).magnitude() <= vec1.magnitude() + vec2.magnitude());
	//EXPECT_TRUE((vec1 + vec3).magnitude() == vec1.magnitude() + vec3.magnitude());
}

TEST(Vector3Test, CrossTest) {
	Vector3 w(1, -7, 1);
	Vector3 v(5, 2, 4);
	Vector3 u(Vector3::cross(w, v));
	cout << u << endl;
	EXPECT_EQ(u * w, 0);
	EXPECT_EQ(u * v, 0);
	//EXPECT_TRUE((vec1 + vec3).magnitude() == vec1.magnitude() + vec3.magnitude());
}