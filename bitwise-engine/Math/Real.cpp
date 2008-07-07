#include "Real.h"

Real RealHelper::ZERO = RealHelper::fromFloat(0.0f);
Real RealHelper::ONE = RealHelper::fromFloat(1.0f);

float
RealHelper::ToFloat(Real r)
{
	return static_cast<float>(r);
}

double
RealHelper::ToDouble(Real r)
{
	return static_cast<double>(r);
}

Real
RealHelper::ToReal(float f)
{
	return static_cast<Real>(f);
}

Real
RealHelper::ToReal(double d)
{
	return static_cast<Real>(d);
}