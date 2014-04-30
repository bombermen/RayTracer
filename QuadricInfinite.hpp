#pragma once
#include "shape.hpp"
#include "Ray.hpp"
class QuadricInfinite : public Shape
{
private:
	//Equation ax² + by² + cz² + dx + ey + fz + j = 0
	float _a, _b, _c, _d, _e, _f, _g, _h, _i, _j;
	float _x, _y, _z;
public:
	QuadricInfinite(void);
	~QuadricInfinite(void);
	QuadricInfinite(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j);
	float getA(){return _a;}
	float getB(){return _b;}
	float getC(){return _c;}
	float getD(){return _d;}
	float getE(){return _e;}
	float getF(){return _f;}
	float getG(){return _g;}
	float getH(){return _h;}
	float getI(){return _i;}
	float getJ(){return _j;}
	float getX(){return _x;}
	float getY(){return _y;}
	float getZ(){return _z;}

	void setA(float nb){_a=nb;}
	void setA(float nb){_b=nb;}
	void setC(float nb){_c=nb;}
	void setD(float nb){_d=nb;}
	void setE(float nb){_e=nb;}
	void setF(float nb){_f=nb;}
	void setG(float nb){_g=nb;}
	void setH(float nb){_h=nb;}
	void setI(float nb){_i=nb;}
	void setJ(float nb){_j=nb;}
	void setX(float nb){_x=nb;}
	void setY(float nb){_y=nb;}
	void setZ(float nb){_z=nb;}

	bool intersect(Ray ray);

};


//TODO
bool intersect(Ray ray)
{
	bool res = false;
	return res;
}