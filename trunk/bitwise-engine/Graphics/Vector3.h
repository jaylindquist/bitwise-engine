#pragma once
#include <BitwiseEngine/Utils/Object.h>

namespace BitwiseEngine {

namespace Math {

class Vector3 : public Object
{
public:
	static const Vector3 UNIT_X;
	static const Vector3 UNIT_Y;
	static const Vector3 UNIT_Z;
	static const Vector3 ZERO;
	static const Vector3 ONE;

	Real x;
	Real y;
	Real z;

	Vector3();
	Vector3(Real inX, Real inY, Real inZ);
	~Vector3();

	Vector3 operator=(Vector3 &in);

	Vector3 Add(Vector3 &in) const;
	Vector3 Clamp(Vector3 &min, Vector3 &max) const;
	Vector3 Cross(Vector3 &in) const;
	Real Distance(Vector3 &in) const;
	Real DistanceSquared(Vector3 &in) const;
	Vector3 Divide(Real s) const;
	Vector3 Divide(Vector3 &in) const;
	Real Dot(Vector3 &in) const;
	bool Equals(Vector3 &in) const;
	Real Length() const;
	Real LengthSquared() const;
	Vector3 Multiply(Real s) const;
	Vector3 Multiply(Vector3 &in) const;
	Vector3 Negate() const;
	Vector3 Normalize() const;
	Vector3 Reflect(Vector3 &normal) const;
	void Set(Real inX, Real inY, Real inZ);
	void Set(Vector3& in);
	Vector3 Subtract(Vector3 &in) const;
	std::string ToString() const;

	static Vector3 Add(Vector3 &in1, Vector3 &in2);
	static Vector3 Clamp(Vector3 &in, Vector3 &min, Vector3 &max);
	static Vector3 Cross(Vector3 &in1, Vector3 &in2);
	static Real Distance(Vector3 &in1, Vector3 &in2);
	static Real DistanceSquared(Vector3 &in1, Vector3 &in2);
	static Vector3 Divide(Vector3 &in, Real s);
	static Vector3 Divide(Vector3 &in1, Vector3 &in2);
	static Real Dot(Vector3 &in1, Vector3 &in2);
	static bool Equals(Vector3 &in1, Vector3 &in2);
	static Real Length(Vector3 &in);
	static Real LengthSquared(Vector3 &in);
	static Vector3 Lerp(Vector3 &in1, Vector3 &in2, Real t);
	static Vector3 Max(Vector3 &in1, Vector3 &in2);
	static Vector3 Min(Vector3 &in1, Vector3 &in2);
	static Vector3 Multiply(Vector3 &in, Real s);
	static Vector3 Multiply(Vector3 &in1, Vector3 &in2);
	static Vector3 Negate(Vector3 &in);
	static Vector3 Normalize(Vector3 &in);
	static Vector3 Reflect(Vector3 &in, Vector3 &normal);
	static Vector3 Subtract(Vector3 &in1, Vector3 &in2);
	
	friend Vector3 operator+(Vector3 &left, Vector3 &right);
	friend Vector3 operator-(Vector3 &left, Vector3 &right);
	friend Vector3 operator*(Vector3 &left, Real &right);
	friend Vector3 operator*(Real &left, Vector3 &right);
	friend Vector3 operator*(Vector3 &left, Vector3 &right);
	friend Vector3 operator/(Vector3 &left, Real &right);
	friend Vector3 operator/(Vector3 &left, Vector3 &right);
	friend Vector3 operator-(Vector3 &in);
	friend bool operator==(Vector3 &left, Vector3 &right);
	friend bool operator!=(Vector3 &left, Vector3 &right);
};

};

};