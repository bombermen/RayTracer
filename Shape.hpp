#pragma once
#include "sceneobject.hpp"
#include "Ray.hpp"
class Shape :
	public SceneObject
{
private:

public:
	Shape(void);
	~Shape(void);
	virtual bool intersect(Ray ray) = 0;
};

