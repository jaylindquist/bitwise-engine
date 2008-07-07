#include "Color.h"

using namespace BitwiseEngine::Math;
using namespace BitwiseEngine::Graphics;


Color Color::WHITE = Color(RealHelper::ONE, RealHelper::ONE, RealHelper::ONE, RealHelper::ONE);
Color Color::BLACK = Color(RealHelper::ZERO, RealHelper::ZERO, RealHelper::ZERO, RealHelper::ONE);
Color Color::RED = Color(RealHelper::ONE, RealHelper::ZERO, RealHelper::ZERO, RealHelper::ONE);
Color Color::GREEN = Color(RealHelper::ZERO, RealHelper::ONE, RealHelper::ZERO, RealHelper::ONE);
Color Color::BLUE = Color(RealHelper::ZERO, RealHelper::ZERO, RealHelper::ONE, RealHelper::ONE);
Color Color::CYAN = Color(RealHelper::ZERO, RealHelper::ONE, RealHelper::ONE, RealHelper::ONE);
Color Color::MAGENTA = Color(RealHelper::ONE, RealHelper::ZERO, RealHelper::ONE, RealHelper::ONE);
Color Color::YELLOW = Color(RealHelper::ONE, RealHelper::ONE, RealHelper::ZERO, RealHelper::ONE);

Color::Color()
{
	r = RealHelper::ONE;
	g = RealHelper::ONE;
	b = RealHelper::ONE;
	a = RealHelper::ONE;
}

Color::Color(Real red, Real green, Real blue)
{
	r = red;
	g = green;
	b = blue;
	a = RealHelper::ONE;
}

Color::Color(Real red, Real green, Real blue, Real alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}