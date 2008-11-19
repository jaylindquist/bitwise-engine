#pragma once
#include <BitwiseEngine/Object.h>

namespace BitwiseEngine {

class Vector3 : public Object
{
public:
	static const Vector3 UNIT_X;
	static const Vector3 UNIT_Y;
	static const Vector3 UNIT_Z;
	static const Vector3 ZERO;
	static const Vector3 ONE;

	float x;
	float y;
	float z;

	Vector3();
	Vector3(float inX, float inY, float inZ);
	~Vector3();

	Vector3 operator=(Vector3 &in);

	Vector3 Add(Vector3 &in) const;
	Vector3 Clamp(Vector3 &min, Vector3 &max) const;
	Vector3 Cross(Vector3 &in) const;
	float Distance(Vector3 &in) const;
	float DistanceSquared(Vector3 &in) const;
	Vector3 Divide(float s) const;
	Vector3 Divide(Vector3 &in) const;
	float Dot(Vector3 &in) const;
	bool Equals(Vector3 &in) const;
	float Length() const;
	float LengthSquared() const;
	Vector3 Multiply(float s) const;
	Vector3 Multiply(Vector3 &in) const;
	Vector3 Negate() const;
	Vector3 Normalize() const;
	Vector3 Reflect(Vector3 &normal) const;
	void Set(float inX, float inY, float inZ);
	void Set(Vector3& in);
	Vector3 Subtract(Vector3 &in) const;
	std::string ToString() const;

	static Vector3 Add(Vector3 &in1, Vector3 &in2);
	static Vector3 Clamp(Vector3 &in, Vector3 &min, Vector3 &max);
	static Vector3 Cross(Vector3 &in1, Vector3 &in2);
	static float Distance(Vector3 &in1, Vector3 &in2);
	static float DistanceSquared(Vector3 &in1, Vector3 &in2);
	static Vector3 Divide(Vector3 &in, float s);
	static Vector3 Divide(Vector3 &in1, Vector3 &in2);
	static float Dot(Vector3 &in1, Vector3 &in2);
	static bool Equals(Vector3 &in1, Vector3 &in2);
	static float Length(Vector3 &in);
	static float LengthSquared(Vector3 &in);
	static Vector3 Lerp(Vector3 &in1, Vector3 &in2, float t);
	static Vector3 Max(Vector3 &in1, Vector3 &in2);
	static Vector3 Min(Vector3 &in1, Vector3 &in2);
	static Vector3 Multiply(Vector3 &in, float s);
	static Vector3 Multiply(Vector3 &in1, Vector3 &in2);
	static Vector3 Negate(Vector3 &in);
	static Vector3 Normalize(Vector3 &in);
	static Vector3 Reflect(Vector3 &in, Vector3 &normal);
	static Vector3 Subtract(Vector3 &in1, Vector3 &in2);
	
	friend Vector3 operator+(Vector3 &left, Vector3 &right);
	friend Vector3 operator-(Vector3 &left, Vector3 &right);
	friend Vector3 operator*(Vector3 &left, float &right);
	friend Vector3 operator*(float &left, Vector3 &right);
	friend Vector3 operator*(Vector3 &left, Vector3 &right);
	friend Vector3 operator/(Vector3 &left, float &right);
	friend Vector3 operator/(Vector3 &left, Vector3 &right);
	friend Vector3 operator-(Vector3 &in);
	friend bool operator==(Vector3 &left, Vector3 &right);
	friend bool operator!=(Vector3 &left, Vector3 &right);
};

}