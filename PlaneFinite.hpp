#pragma once
#include "shape.h"
class PlaneFinite :
	public Shape
{
private:
	unsigned int _type;
public:
	PlaneFinite(void);
	~PlaneFinite(void);

	
	float getType(){return _type;}

	void setType(unsigned type){_type=type;}
};

