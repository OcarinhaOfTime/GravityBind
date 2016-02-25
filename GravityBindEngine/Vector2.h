#pragma once
#include <math.h>
#include <iostream>

using std::ostream;

namespace GravityBind {
	struct Vector2 {
		float x;
		float y;

		Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		float magnitude() {
			return sqrt(pow(x, 2) + pow(y, 2));
		}

		float magnitudeSqr() {
			return pow(x, 2) + pow(y, 2);
		}

		static Vector2 zero() {
			return Vector2();
		}

		static Vector2 one() {
			return Vector2(1, 1);
		}
	};

	inline Vector2 operator+(const Vector2& left, const Vector2& right) {
		return Vector2(left.x + right.x, left.y + right.y);
	}

	inline Vector2 operator-(const Vector2& left, const Vector2& right) {
		return Vector2(left.x - right.x, left.y - right.y);
	}

	inline Vector2 operator-(const Vector2& vector) {
		return Vector2(-vector.x, -vector.y);
	}

	inline Vector2 operator*(const float& scalar, const Vector2& vector) {
		return Vector2(vector.x * scalar, vector.y * scalar);
	}

	inline Vector2 operator*(const Vector2& vector, const float& scalar) {
		return Vector2(vector.x * scalar, vector.y * scalar);
	}

	inline float operator*(const Vector2& left, const Vector2& right) {
		return left.x * right.x + left.y * right.y;
	}

	inline float dot(const Vector2& left, const Vector2& right) {
		return left.x * right.x + left.y * right.y;
	}

	inline Vector2 cross(const Vector2& left, const Vector2& right) {
		return Vector2(left.x * right.x + left.y * right.y);
	}

	inline bool operator==(const Vector2& left, const Vector2& right) {
		return left.x == right.x && left.y == right.y;
	}

	inline ostream& operator<<(ostream& os, const Vector2& vec) {
		os << "{" << vec.x << ", " << vec.y << "}";
		return os;
	}
}
