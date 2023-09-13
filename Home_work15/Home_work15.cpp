#include <iostream>
#include <string>
#include <cmath>


class Rectangle {
public:
	static int count() {
		static int counter = 0;
		return counter++;
	};
	float leght{}, hight{};
	float getArea() {
		return leght * hight;
	}
	float getPerimeter() {
		return 2 * (leght + hight);
	}
	Rectangle(float leght, float hight) : leght{ leght }, hight{ hight } {
		count();
	}
	Rectangle() {
		leght = 10;
		hight = 8;
		count();
	}
};

class Vector2D {
private:
	float x = 0.0;
	float y = 0.0;
public:
	
	Vector2D(float x, float y) : x{ x }, y{ y } {}
	Vector2D& operator=(const Vector2D& secondVector) {
		this->x = secondVector.x;
		this->y = secondVector.y;
		return *this;
	}
	Vector2D operator+(const Vector2D& secondVector) {
		this->x += secondVector.x;
		this->y += secondVector.y;
		return *this;
	}
	Vector2D operator-(const Vector2D& secondVector) {
		this->x -= secondVector.x;
		this->y -= secondVector.y;
		return *this;
	}

	friend Vector2D operator+(const Vector2D& firstVector, const Vector2D& secondVector) {

		return firstVector + secondVector;
	}
	friend Vector2D operator-(const Vector2D& firstVector, const Vector2D& secondVector) {

		return firstVector - secondVector;
	}
	float operator()() {
		return sqrt(x * x + y * y);
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
};

int main() {
	Rectangle r[4]{ {0,0}, {-5,1}, {13,5} };
	for (int i = 0; i < 4; i++) {
		std::cout << "Rectangle " << i << " area: " << r[i].getArea() << " perimeter:" << r[i].getPerimeter() << std::endl;
	}
	std::cout << Rectangle::count() << std::endl;

	Vector2D i{ 0, 0 };
	i = { 0, 1 };
	Vector2D testVec{ 1.2, 5.6 };
	std::cout << testVec << std::endl;
	std::cin >> testVec;
	std::cout << testVec << std::endl;
}