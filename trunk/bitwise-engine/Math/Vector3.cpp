#include "Vector3.h"

static const Vector3 UNIT_X = Vector3(1.0f, 0.0f, 0.0f);
static const Vector3 UNIT_Y = Vector3(0.0f, 1.0f, 0.0f);
static const Vector3 UNIT_Z = Vector3(0.0f, 0.0f, 1.0f);
static const Vector3 ZERO = Vector3(0.0f, 0.0f, 0.0f);
static const Vector3 ONE = Vector3(1.0f, 1.0f, 1.0f);

Vector3(void)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3(float inX, float inY, float inZ)
{
	this->x = inX;
	this->y = inY;
	this->z = inZ;
}

~Vector3(void)
{
}

Vector3 Clamp(Vector3 &min, Vector3 &max) const;
static Vector3 Clamp(Vector3 &in, Vector3 &min, Vector3 &max);
static void Clamp(Vector3 &in, Vector3 &min, Vector3 &max, Vector3 &out);

Vector3 Cross(Vector3 &in) const;
static Vector3 Cross(Vector3 &in1, Vector3 &in2);
static void Cross(Vector3 &in1, Vector3 &in2, Vector3 &out);

float Distance(Vector3 &in) const;
static float Distance(Vector3 &in1, Vector3 &in2);
static void Distance(Vector3 &in1, Vector3 &in2, float &out);

bool 
Vector3::Equals(Vector3 &in) const
{
	
}

static bool 
Vector3::Equals(Vector3 &in1, Vector3 &in2)
{

}

static void 
Vector3::Equals(Vector3 &in1, Vector3 &in2, bool &out)
{

}

float Length() const;
static float Length(Vector3 &in);
static void Length(Vector3 &in, float &out);

static Vector3 
Vector3::Max(Vector3 &in1, Vector3 &in2)
{

}

static void 
Vector3::Max(Vector3 &in1, Vector3 &in2, Vector3 &out)
{

}

static Vector3 
Vector3::Min(Vector3 &in1, Vector3 &in2)
{

}

static void 
Vector3::Min(Vector3 &in1, Vector3 &in2, Vector3 &out)
{

}

Vector3 Normalize() const;
static Vector3 Normalize(Vector3 &in);
static void Normalize(Vector3 &in, Vector3 &out);

Vector3 Reflect(Vector3 &normal) const;
static Vector3 Reflect(Vector3 &in, Vector3 &normal);
static void Reflect(Vector3 &in, Vector3 &normal, Vector3 &out);
