#pragma once
#include <math.h>
#include <iostream>

using std::ostream;

namespace GravityBind {
	struct Vector3 {
		float x;
		float y;
		float z;

		Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

		float magnitude() {
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}

		float magnitudeSqr() {
			return pow(x, 2) + pow(y, 2) + pow(z, 2);
		}

		static Vector3 zero() {
			return Vector3();
		}

		static Vector3 one() {
			return Vector3(1, 1, 1);
		}

		static Vector3 cross(const Vector3& left, const Vector3& right) {

			return Vector3(left.y * right.z - left.z * right.y,
				left.z * right.x - left.x * right.z,
				left.x * right.y - left.y * right.x);
		}
	};

	inline Vector3 operator+(const Vector3& left, const Vector3& right) {
		return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	inline Vector3 operator-(const Vector3& left, const Vector3& right) {
		return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	inline Vector3 operator-(const Vector3& vector) {
		return Vector3(-vector.x, -vector.y, -vector.z);
	}

	inline Vector3 operator*(const float& scalar, const Vector3& vector) {
		return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	inline Vector3 operator*(const Vector3& vector, const float& scalar) {
		return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	inline float operator*(const Vector3& left, const Vector3& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	inline float dot(const Vector3& left, const Vector3& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	inline bool operator==(const Vector3& left, const Vector3& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z;
	}

	inline ostream& operator<<(ostream& os, const Vector3& vec) {
		os << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
		return os;
	}
}
