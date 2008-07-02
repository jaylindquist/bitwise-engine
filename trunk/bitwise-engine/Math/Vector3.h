#pragma once

#include <string>

namespace BitwiseEngine
{

class Vector3
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

	Vector3(void);
	Vector3(float inX, float inY, float inZ);
	~Vector3(void);

	Vector3 operator=(Vector3 &in);

	Vector3 Add(Vector3 &in) const;
	static Vector3 Add(Vector3 &in1, Vector3 &in2);
	static void Add(Vector3 &in1, Vector3 &in2, Vector3 &out);

	Vector3 Clamp(Vector3 &min, Vector3 &max) const;
	static Vector3 Clamp(Vector3 &in, Vector3 &min, Vector3 &max);
	static void Clamp(Vector3 &in, Vector3 &min, Vector3 &max, Vector3 &out);

	Vector3 Cross(Vector3 &in) const;
	static Vector3 Cross(Vector3 &in1, Vector3 &in2);
	static void Cross(Vector3 &in1, Vector3 &in2, Vector3 &out);

	float Distance(Vector3 &in) const;
	static float Distance(Vector3 &in1, Vector3 &in2);
	static void Distance(Vector3 &in1, Vector3 &in2, float &out);

	float DistanceSquared(Vector3 &in) const;
	static float DistanceSquared(Vector3 &in1, Vector3 &in2);
	static void DistanceSquared(Vector3 &in1, Vector3 &in2, float &out);

	Vector3 Divide(float s) const;
	static Vector3 Divide(Vector3 &in, float s);
	static void Divide(Vector3 &in, float s, Vector3 &out);

	Vector3 Divide(Vector3 &in) const;
	static Vector3 Divide(Vector3 &in1, Vector3 &in2);
	static void Divide(Vector3 &in1, Vector3 &in2, Vector3 &out);

	float Dot(Vector3 &in) const;
	static float Dot(Vector3 &in1, Vector3 &in2);
	static void Dot(Vector3 &in1, Vector3 &in2, float &out);

	bool Equals(Vector3 &in) const;
	static bool Equals(Vector3 &in1, Vector3 &in2);
	static void Equals(Vector3 &in1, Vector3 &in2, bool &out);

	float Length() const;
	static float Length(Vector3 &in);
	static void Length(Vector3 &in, float &out);

	float LengthSquared() const;
	static float LengthSquared(Vector3 &in);
	static void LengthSquared(Vector3 &in, float &out);

	static Vector3 Lerp(Vector3 &in1, Vector3 &in2, float t);
	static void Lerp(Vector3 &in1, Vector3 &in2, float t, Vector3 &out);

	static Vector3 Max(Vector3 &in1, Vector3 &in2);
	static void Max(Vector3 &in1, Vector3 &in2, Vector3 &out);

	static Vector3 Min(Vector3 &in1, Vector3 &in2);
	static void Min(Vector3 &in1, Vector3 &in2, Vector3 &out);

	Vector3 Multiply(float s) const;
	static Vector3 Multiply(Vector3 &in, float s);
	static void Multiply(Vector3 &in, float s, Vector3 &out);

	Vector3 Multiply(Vector3 &in) const;
	static Vector3 Multiply(Vector3 &in1, Vector3 &in2);
	static void Multiply(Vector3 &in1, Vector3 &in2, Vector3 &out);

	Vector3 Negate() const;
	static Vector3 Negate(Vector3 &in);
	static void Negate(Vector3 &in, Vector3 &out);

	Vector3 Normalize() const;
	static Vector3 Normalize(Vector3 &in);
	static void Normalize(Vector3 &in, Vector3 &out);

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

	Vector3 Reflect(Vector3 &normal) const;
	static Vector3 Reflect(Vector3 &in, Vector3 &normal);
	static void Reflect(Vector3 &in, Vector3 &normal, Vector3 &out);

	void Set(float inX, float inY, float inZ);
	void Set(Vector3& in);

	Vector3 Subtract(Vector3 &in) const;
	static Vector3 Subtract(Vector3 &in1, Vector3 &in2);
	static void Subtract(Vector3 &in1, Vector3 &in2, Vector3 &out);

	std::string ToString() const;
};

#include "Vector3.inl"

}