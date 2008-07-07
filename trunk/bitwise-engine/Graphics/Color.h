#pragma once


#include "Math/Real.h"

namespace BitwiseEngine
{

namespace Graphics
{

class Color
{
public:
	BitwiseEngine::Math::Real r;
	BitwiseEngine::Math::Real g;
	BitwiseEngine::Math::Real b;
	BitwiseEngine::Math::Real a;

	static Color WHITE;
	static Color BLACK;
	static Color RED;
	static Color GREEN;
	static Color BLUE;
	static Color CYAN;
	static Color MAGENTA;
	static Color YELLOW;

	Color();
	Color(BitwiseEngine::Math::Real red, BitwiseEngine::Math::Real green, BitwiseEngine::Math::Real blue);
	Color(BitwiseEngine::Math::Real red, BitwiseEngine::Math::Real green, BitwiseEngine::Math::Real blue, BitwiseEngine::Math::Real alpha);
};

};
};