#include <gtest\gtest.h>
#include <Vector2.h>


using GravityBind::Vector2;

TEST(Vector2DTest, Vector2DConstructor) {
	Vector2 vector1;
	Vector2 vector2(5, 6);

	EXPECT_TRUE(vector1.x == 0 && vector1.y == 0);
	EXPECT_TRUE(vector2.x == 5 && vector2.y == 6);
}

TEST(Vector2DTest, Vector2DAdition) {
	Vector2 vector1;
	Vector2 vector2(5, 6);
	Vector2 vector3(7, 3);

	Vector2 result = vector1 + vector2;


	EXPECT_TRUE(result.x == 5 && result.y == 6);

	result = vector2 + vector3;

	EXPECT_TRUE(result.x == 12 && result.y == 9);
}

TEST(Vector2DTest, Vector2DSubtraction) {
	Vector2 vector1;
	Vector2 vector2(5, 6);
	Vector2 vector3(7, 3);
	Vector2 vector4(10, 33);

	Vector2 result = vector3 - vector2;

	EXPECT_TRUE(result.x == 2 && result.y == -3);
	result = -vector4;
	EXPECT_TRUE(result.x == -10 && result.y == -33);
}

TEST(Vector2DTest, Vector2DScalarMulti) {
	Vector2 vector1;
	Vector2 vector2(5, 6);
	Vector2 vector3(7, 3);
	Vector2 vector4(10, 33);
	float scalar = 3;

	Vector2 result = scalar * vector2;

	EXPECT_TRUE(result.x == 15 && result.y == 18);
	result = vector2 * scalar;
	EXPECT_EQ(result.x, 15);
	EXPECT_EQ(result.y, 18);
}

TEST(Vector2DTest, Vector2DScalarDot) {
	Vector2 vector1;
	Vector2 vector2(2, 7);
	Vector2 vector3(5, 1);

	float result = vector3 * vector2;

	EXPECT_TRUE(result == 17);
}

TEST(Vector2DTest, Vector2DSDotProperties) {
	Vector2 vec1(2, 3);
	Vector2 vec2(5, 7);
	Vector2 vec3(11, 13);
	float c = 313;

	EXPECT_EQ(vec1 * vec2, vec2 * vec1);
	EXPECT_EQ((vec1 + vec2) * vec3, vec1 * vec3 + vec2 * vec3);
	EXPECT_EQ(c * (vec1 * vec2), (c * vec2) * vec1);
}

TEST(Vector2DTest, LenghtProof) {
	Vector2 vec1(2, 3);
	Vector2 vec2(313, 69);

	EXPECT_EQ(vec1 * vec1, vec1.magnitudeSqr());
	EXPECT_EQ(vec2 * vec2, vec2.magnitudeSqr());
}

TEST(Vector2DTest, CauchySchwarzTest) {
	Vector2 vec1(2, 3);
	Vector2 vec2(5, 7);
	Vector2 vec3(20, 30);

	EXPECT_TRUE(abs(vec1 * vec2) <= vec1.magnitude() * vec2.magnitude());
	EXPECT_TRUE(abs(vec1 * vec3) == vec1.magnitude() * vec3.magnitude());
}

TEST(Vector2DTest, VectorTriangleInnequality) {
	Vector2 vec1(2, 3);
	Vector2 vec2(5, 7);
	Vector2 vec3(20, 30);

	EXPECT_TRUE((vec1 + vec2).magnitude() <= vec1.magnitude() + vec2.magnitude());
	EXPECT_TRUE((vec1 + vec3).magnitude() == vec1.magnitude() + vec3.magnitude());
}

//Properties test
TEST(Vector2DTest, Vector2DEquals) {
	Vector2 vector1;
	Vector2 vector2(5, 6);
	Vector2 vector3(7, 3);
	Vector2 vector4(10, 33);

	EXPECT_TRUE(vector2 + vector1 == vector2);
	EXPECT_TRUE(vector2 == vector2 + vector1);
	EXPECT_TRUE(vector2 + vector3 == vector3 + vector2);
	EXPECT_TRUE((vector2 + vector3) + vector4 == vector2 + (vector3 + vector4));
}