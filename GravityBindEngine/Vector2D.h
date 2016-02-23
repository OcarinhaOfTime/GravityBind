#pragma once

namespace GravityBind {
	struct Vector2D {
		float x;
		float y;

		Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
	};

	Vector2D operator+(const Vector2D& left, const Vector2D& right) {
		return Vector2D();
	}

	Vector2D operator*(const float& scalar, const Vector2D& vector) {
		return Vector2D();
	}

	Vector2D operator*(const Vector2D& left, const Vector2D& right) {
		return Vector2D();
	}
}
