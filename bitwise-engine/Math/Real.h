#pragma once

namespace BitwiseEngine {

namespace Math {

#ifdef BE_REAL_DOUBLE
typedef double Real
#else
typedef float Real
#endif

class RealHelper
{
public:
	static float ToFloat(Real r);
	static double ToDouble(Real r);

	static Real ToReal(float f);
	static Real ToReal(double d);

	static Real ZERO;
	static Real ONE;

};

};

};