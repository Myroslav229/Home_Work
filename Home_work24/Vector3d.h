#pragma once
#include <math.h>
#include<iostream>

class Vector3D {
private:
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
public:

	Vector3D(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}
	Vector3D(const Vector3D&) = default;
	Vector3D(Vector3D&& head, Vector3D&& tail) {
		x = tail.x - head.x;
		y = tail.y - head.y;
		z = tail.z - head.z;
	}
	Vector3D crossProduct(Vector3D& other) const {
		return { y * other.z - other.y*z, -1*(x * other.z - other.x * z),x * other.y - other.x * y };
	}
	Vector3D negative() const {
		return { x * (-1), y * (-1), z * (-1) };
	}

	Vector3D & operator=(const Vector3D& secondVector) = default;
	Vector3D operator+(const Vector3D& secondVector) const {
		return { x + secondVector.x, y + secondVector.y , z + secondVector.z};
	}
	Vector3D operator-(const Vector3D& secondVector) const {
		return { x - secondVector.x, y - secondVector.y , z - secondVector.z };
	}

	friend Vector3D operator+(const Vector3D& firstVector, const Vector3D& secondVector) {
		return { firstVector.x + secondVector.x, firstVector.y + secondVector.y , firstVector.z + secondVector.z };
	}
	friend Vector3D operator-(const Vector3D& firstVector, const Vector3D& secondVector) {
		return { firstVector.x - secondVector.x, firstVector.y - secondVector.y , firstVector.z - secondVector.z };
	}
	float operator()() const {

		return module();
	}
	float& operator[](int i) {
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		case 2: default:
			return z;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
		out << "Output: {" << vec.x << "; " << vec.y << "; " << vec.z << "}";
		return out;
	};
	friend std::istream& operator>>(std::istream& in, Vector3D& vec) {
		return in >> vec.x >> vec.y >> vec.z;
	};
	float module() const {
		return sqrt(x * x + y * y + z * z);
	}
};