#pragma once

#include <math.h>
#include <float.h>
#include<iostream>

namespace VectorRelativeState {
	enum {
		Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle
	};
}
class Vector2D {
private:
	enum class VectorRelativeState {
		Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle
	};

public:
	
	float x = 0.0;
	float y = 0.0;
	Vector2D() = default;
	Vector2D(float x, float y) : x{ x }, y{ y } {}
	Vector2D(float x0, float y0, float x1, float y1) : x{ x1 - x0 }, y{ y1 - y0 } {}
	Vector2D(const Vector2D&) = default;
	Vector2D(Vector2D&&) = default;
	Vector2D& operator=(Vector2D&&) = default;

	float dotProduct(const Vector2D& other) const {
		return x * other.x + y * other.y;
	}

	Vector2D negative() const {
		return { x * (-1), y * (-1) };
	}

	Vector2D operator=(const Vector2D& secondVector) const {
		return { secondVector.x, secondVector.y };
	}

	Vector2D operator+(const Vector2D& secondVector) const {
		return { x + secondVector.x, y + secondVector.y };
	}

	Vector2D operator-(const Vector2D& secondVector) const {
		return { x - secondVector.x, y - secondVector.y };
	}

	friend Vector2D operator+(const Vector2D& firstVector, const Vector2D& secondVector) {
		return { firstVector.x + secondVector.x, firstVector.y + secondVector.y };
	}

	friend Vector2D operator-(const Vector2D& firstVector, const Vector2D& secondVector) {
		return { firstVector.x - secondVector.x, firstVector.y - secondVector.y };
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector2D& vec) {
		out << "Output: {" << vec.x << "; " << vec.y << "}";
		return out;
	};

	friend std::istream& operator>>(std::istream& in, Vector2D& vec) {
		in >> vec.x >> vec.y;
		return in;
	};

	float moduleSquarted() const {
		return x * x + y * y;
	}
	float module() const {
		return sqrt(moduleSquarted());
	}
	VectorRelativeState getRelativeState(const Vector2D& other) const {
		double cos = dotProduct(other) / (module() * other.module());
		std::cout << cos << std::endl;

		if (cos >= 1) { return VectorRelativeState::Identical; }
		if (cos == x / module() || cos == y / module()) { VectorRelativeState::coDirected; }
		if (cos == 0) { return VectorRelativeState::RightAngle; }
		if (cos <= -1) { return VectorRelativeState::OppositeDirected; }
		if (cos < 1 && cos > 0) { return VectorRelativeState::AcuteAngle; }
		if (cos < 0 && cos > -1) { return VectorRelativeState::ObtuseAngle; }
	}

	bool operator ==(const Vector2D& other) const { return x == other.x && y == other.y; }

	bool operator !=(const Vector2D& other) const { return x != other.x|| y != other.y; }

	Vector2D operator *(float other) const { return { x * other, y * other }; }

	Vector2D operator *(const Vector2D& other) const { return {x * other.x, y * other.y}; }

	Vector2D operator /(float val) const { return { x / val, y / val }; }

	Vector2D operator /(const Vector2D& other) const { return { x / other.x, y / other.y }; }

	Vector2D& operator +=(const Vector2D& other){
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2D& operator -=(const Vector2D& other){
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2D& operator *=(float val){
		x *= val;
		y *= val;
		return *this;
	}

	Vector2D& operator *=(const Vector2D& other){
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2D& operator /=(float val)
	{
		float invRhs = 1.0f / val;
		x *= invRhs;
		y *= invRhs;
		return *this;
	}

	Vector2D& operator /=(const Vector2D& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}
	Vector2D normalized() {
		if (module() < FLT_EPSILON) {
			return {};
		}
		float invLen = 1 / module();
		return { x * invLen,y * invLen };
	}
	
	void normalize() {
		if (module() < FLT_EPSILON) { return; }
		float invLen = 1 / module();
		x *= invLen;  y *= invLen;
	}
	
	//void scale(float factorX, float factorY) {
	//	x = x * factorX;
	//	y = y * factorY;
	//}
};
// vector 2d
