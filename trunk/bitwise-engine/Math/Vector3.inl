inline Vector3 
Vector3::operator=(Vector3 &in)
{
	x = in.x;
	y = in.y;
	z = in.z;

	return *this;
}

inline Vector3 
Vector3::Add(Vector3 &in) const
{
	return Vector3(
			x + in.x,
			y + in.y,
			z + in.z);
}

inline static Vector3
Vector3::Add(Vector3 &in1, Vector3 &in2)
{
	return Vector3(
			in1.x + in2.x,
			in1.y + in2.y,
			in1.z + in2.z);
}

inline static void 
Vector3::Vector3 Add(Vector3 &in1, Vector3 &in2, Vector3 &out)
{
	out.Set(
		in1.x + in2.x,
		in1.y + in2.y,
		in1.z + in2.z);
}


inline float 
Vector3::DistanceSquared(Vector3 &in) const
{
	float din = in - *this;
	return din.LengthSquared();
}

inline static float 
Vector3::DistanceSquared(Vector3 &in1, Vector3 &in2)
{
	float din = in2 - in1;
	return din.LengthSquared();
}

inline static void 
Vector3::DistanceSquared(Vector3 &in1, Vector3 &in2, float &out)
{
	float din = in2 - in1;
	out = din.LengthSquared();
}

inline Vector3 
Vector3::Divide(float s) const
{
	return Vector3(
				x / s,
				y / s,
				z / s);
}

inline static Vector3 
Vector3::Divide(Vector3 &in, float s)
{
	return Vector3(
				in.x / s,
				in.y / s,
				in.z / s);
}

inline static void 
Vector3::Divide(Vector3 &in, float s, Vector3 &out)
{
	out.x = in.x / s;
	out.y = in.y / s;
	out.z = in.z / s;
}

inline Vector3 
Vector3::Divide(Vector3 &in) const
{
	return Vector3(
				x / in.x,
				y / in.y,
				z / in.z);
}

inline static Vector3 
Vector3::Divide(Vector3 &in1, Vector3 &in2)
{
	return Vector3(
				in.x / in.x,
				in.y / in.y,
				in.z / in.z);
}

inline static void 
Vector3::Divide(Vector3 &in1, Vector3 &in2, Vector3 &out)
{
	out.x = in.x / in.x;
	out.y = in.y / in.y;
	out.z = in.z / in.z;
}

inline float 
Vector3::Dot(Vector3 &in) const
{
	return x * in.x + y * in.y + z * in.z;
}

inline static float 
Vector3::Dot(Vector3 &in1, Vector3 &in2)
{
	return in1.x * in2.x + in1.y * in2.y + in1.z * in2.z;
}

inline static void 
Vector3::Dot(Vector3 &in1, Vector3 &in2, float &out)
{
	out = in1.x * in2.x + in1.y * in2.y + in1.z * in2.z;
}

inline float 
Vector3::LengthSquared() const
{
	return x * x + y * y + z * z;
}

inline static float 
Vector3::LengthSquared(Vector3 &in)
{
	return in.x * in.x + in.y * in.y + in.z * in.z;
}

inline static void 
Vector3::LengthSquared(Vector3 &in, float &out)
{
	out = in.x * in.x + in.y * in.y + in.z * in.z;
}

inline static Vector3 
Vector3::Lerp(Vector3 &in1, Vector3 &in2, float t) 
{

}

inline static void 
Vector3::Lerp(Vector3 &in1, Vector3 &in2, float t, Vector3 &out)
{

}

inline Vector3 
Vector3::Multiply(float s) const
{
	return Vector3(
				x * s,
				y * s,
				z * s);
}

inline static Vector3 
Vector3::Multiply(Vector3 &in, float s)
{
	return Vector3(
				in.x * s,
				in.y * s,
				in.z * s);
}

inline static void 
Vector3::Multiply(Vector3 &in, float s, Vector3 &out)
{
	out.x = in.x * s;
	out.y = in.y * s;
	out.z = in.z * s;
}

inline Vector3 
Vector3::Multiply(Vector3 &in) const
{
	return Vector3(
				x * in.x,
				y * in.y,
				z * in.z);
}

inline static Vector3 
Vector3::Multiply(Vector3 &in1, Vector3 &in2)
{
	return Vector3(
				in.x * in.x,
				in.y * in.y,
				in.z * in.z);
}

inline static void 
Vector3::Multiply(Vector3 &in1, Vector3 &in2, Vector3 &out)
{
	out.x = in.x * in.x;
	out.y = in.y * in.y;
	out.z = in.z * in.z;
}

inline Vector3 
Vector3::Negate() const
{
	return Vector3(-x, -y, -z);
}

inline static Vector3 
Vector3::Negate(Vector3 &in)
{
	return Vector3(-in.x, -in.y, -in.z);
}

inline static void 
Vector3::Negate(Vector3 &in, Vector3 &out)
{
	out = Vector3(-in.x, -in.y, -in.z);
}

inline Vector3 
Vector3::operator+(Vector3 &left, Vector3 &right)
{
	return Vector3::add(left, right);
}

inline Vector3 
Vector3::operator-(Vector3 &left, Vector3 &right)
{
	return Vector3::subtract(left, right);
}

inline Vector3 
Vector3::operator*(Vector3 &left, float &right)
{
	return Vector3::multiply(left, right);
}

inline Vector3 
Vector3::operator*(float &left, Vector3 &right)
{
	return Vector3::multiply(right, left);
}

inline Vector3 
Vector3::operator*(Vector3 &left, Vector3 &right)
{
	return Vector3::multiply(left, right);
}

inline Vector3 
Vector3::operator/(Vector3 &left, float &right)
{
	return Vector3::divide(left, right);
}

inline Vector3 
Vector3::operator/(Vector3 &left, Vector3 &right)
{
	return Vector3::divide(left, right);
}

inline Vector3 
Vector3::operator-(Vector3 &in)
{
	return Vector3::negate(in);
}

inline bool 
Vector3::operator==(Vector3 &left, Vector3 &right)
{
	return Vector.equals(left, right);
}

inline bool 
Vector3::operator!=(Vector3 &left, Vector3 &right)
{
	return !Vector.equals(left, right);
}


inline void 
Vector3::Set(float inX, float inY, float inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

inline void 
Vector3::Set(Vector3& in)
{
	x = in.x;
	y = in.y;
	z = in.z;
}


inline Vector3 
Vector3::Subtract(Vector3 &in) const
{
	return Vector3(
				x - in.x,
				y - in.y,
				z - in.z);

}

inline static Vector3 
Vector3::Subtract(Vector3 &in1, Vector3 &in2)
{
	return Vector3(
				in1.x - in2.x,
				in1.y - in2.y,
				in1.z - in2.z);
}

inline static void 
Vector3::Subtract(Vector3 &in1, Vector3 &in2, Vector3 &out)
{
	out.Set(in1.x - in2.x,
			in1.y - in2.y,
			in1.z - in2.z);
}

inline std::string
Vector3:: ToString() const
{
	return "{" + x + ", " + y + ", " + z + "}";
}
