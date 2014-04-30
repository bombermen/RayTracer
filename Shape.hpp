#pragma once
#include "sceneobject.h"
#include "Ray.h"
class Shape :
	public SceneObject
{
private:

public:
	Shape(void);
	~Shape(void);
	virtual bool intersect(Ray ray) = 0;
};

