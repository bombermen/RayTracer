#pragma once

#include "Mat4f.hpp"

#define NB_VALUES 4

class Vec4f
{
public:
	Vec4f();
	Vec4f(float f);
	Vec4f(float * values);
	Vec4f(const Vec4f& v);
	Vec4f(float x, float y, float z);
	Vec4f(float x, float y, float z, float w);

	//getters
	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;
	//alias getters for colors
	float getR() const;
	float getG() const;
	float getB() const;
	float getA() const;

	float * getXYZW() const;
	float * getRGBA() const;

	//setters
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setW(float w);
	//alias setters for colors
	void setR(float r);
	void setG(float g);
	void setB(float b);
	void setA(float a);

	void setXYZW(float * values);
	void setRGBA(float * values);
	void setXYZW(float x, float y, float z, float w);
	void setRGBA(float r, float g, float b, float a);

	//operators
	float operator* (const Vec4f& rhs) const;
	Vec4f operator* (const Mat4f& rhs) const;
	Vec4f operator+ (const Vec4f& rhs) const;
	Vec4f operator- (const Vec4f& rhs) const;

	Vec4f operator= (const Vec4f& rhs);
	Vec4f operator*= (const Mat4f& rhs) const;
	Vec4f operator+= (const Vec4f& rhs) const;
	Vec4f operator-= (const Vec4f& rhs) const;
	
private:
	float _values[NB_VALUES];
};

