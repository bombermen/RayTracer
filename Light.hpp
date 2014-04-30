#pragma once
#include "sceneobject.h"
#include "vec4f.h"

class Light :
	public SceneObject
{
private:
	unsigned int _type;
	vec4f _color;
	float _distance;
	float _blend;
public:
	Light(void);
	~Light(void);
	//To all Light
	Light(unsigned int type);
	//To all Light
	Light(unsigned int type, vec4f color);
	//point & spot only
	Light(unsigned int type, vec4f color, float distance);
	//spot only
	Light(unsigned int type, vec4f color, float distance, float blend);
	//point & spot only
	Light(unsigned int type, float distance);
	//spot only
	Light(unsigned int type, float distance, float blend);
};

