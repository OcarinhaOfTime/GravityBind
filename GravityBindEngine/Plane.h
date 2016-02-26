#pragma once
#include <iostream>
#include <Vector3.h>

namespace GravityBind {
	struct Plane {
		Vector3 normal;
		Vector3 point;

		Plane(Vector3 normal, Vector3 point) : normal(normal), point(point){}

		bool isInside(Vector3 _point) {
			return normal * (_point - point) == 0;
		}
	};

	inline ostream& operator<<(ostream& os, const Plane& plane) {
		os << "{" << plane.normal << ", " << plane.point << "}";
		return os;
	}
}