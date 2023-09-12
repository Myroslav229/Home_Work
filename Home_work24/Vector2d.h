#pragma once
#include <math.h>
#include<iostream>
namespace VectorRelativeState {
	enum {
		Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle
	};
}
class Vector2D {
private:
	float x = 0.0;
	float y = 0.0;
	enum class VectorRelativeState {
		Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle
	};
	
public:

	Vector2D(float x, float y) : x{ x }, y{ y } {}
	Vector2D(float x0, float y0, float x1, float y1) : x{ x1 - x0 }, y{ y1 - y0 } {}
	Vector2D(const Vector2D&) = default;
	float dotProduct( const Vector2D& other) const {
		return x*other.x + y*other.y;
	}
	Vector2D negative() const {
		return { x * (-1), y * (-1) };
	}

	Vector2D operator=(const Vector2D& secondVector) const {
		return { secondVector.x, secondVector.y };
	}
	Vector2D operator+(const Vector2D& secondVector) const  {
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
	float operator()() const {

		return module();
	}
	float& operator[](int i) {
		if (i == 0) return x;
		else if (i == 1) return y;
	}
	friend std::ostream& operator<<(std::ostream& out, const Vector2D& vec) {
		out << "Output: {" << vec.x << "; " << vec.y << "}";
		return out;
	};
	friend std::istream& operator>>(std::istream& in, Vector2D& vec) {
		in >> vec.x >> vec.y;
		return in;
	};
	float module() const {
		return sqrt(x * x + y * y);
	}
	VectorRelativeState getRelativeState(const Vector2D& other) const {
		double cos = dotProduct(other)/(module()*other.module());
		std::cout << cos << std::endl;

		if (cos >= 1) { return VectorRelativeState::Identical; }
		if (cos == x / module() || cos == y / module()) { VectorRelativeState::coDirected; }
		if (cos == 0) { return VectorRelativeState::RightAngle; }
		if (cos <= -1) { return VectorRelativeState::OppositeDirected; }
		if (cos < 1 && cos > 0) { return VectorRelativeState::AcuteAngle; }
		if (cos < 0 && cos > -1) { return VectorRelativeState::ObtuseAngle; }
	}
	void scale(float factorX, float factorY) {
		x = x * factorX;
		y = y * factorY;
	}
};