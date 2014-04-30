#pragma once

#include "vec4f.hpp"

class Ray
{
private:
	vec4f _origin;
	vec4f _direction;
public:
	Ray(void);
	~Ray(void);
	Ray(vec4f origin, vec4f destination);
};
