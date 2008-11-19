#pragma once
#include <BitwiseEngine/Math/Real.h>
#include <BitwiseEngine/Graphics/Real.h>

namespace BitwiseEngine {

namespace Graphics {

class Vertex
{
public:
	Color ambient;
	Color diffuse;
	Color specular;
	Color emmissive;
	Color color;

	Math::Real shininess;
	Math::Real alpha;

	Math::Vector4 textureCoords;
	Math::Vector4 normal;
	Math::Vector4 location;

};

};
};