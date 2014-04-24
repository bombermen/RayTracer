#include "Vec4f.hpp"

Vec4f::Vec4f()
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);
	this->setW(1);
}

Vec4f::Vec4f(float f)
{
	this->setXYZW(f, f, f, 1);
}

Vec4f::Vec4f(float x, float y, float z)
{
	this->setXYZW(x, y, z, 1);
}

Vec4f::Vec4f(float x, float y, float z, float w)
{
	this->setXYZW(x, y, z, w);
}

Vec4f::Vec4f(float * values)
{
	this->setXYZW(values);
}

Vec4f::Vec4f(const Vec4f& v)
{
	this->setXYZW(v.getXYZW());
}

float Vec4f::getX() const { return this->_values[0]; }
float Vec4f::getY() const { return this->_values[1]; }
float Vec4f::getZ() const { return this->_values[2]; }
float Vec4f::getW() const { return this->_values[3]; }
float Vec4f::getR() const { return this->_values[0]; }
float Vec4f::getG() const { return this->_values[1]; }
float Vec4f::getB() const { return this->_values[2]; }
float Vec4f::getA() const { return this->_values[3]; }

void Vec4f::setX(float x) { this->_values[0] = x; }
void Vec4f::setY(float x) { this->_values[1] = x; }
void Vec4f::setZ(float x) { this->_values[2] = x; }
void Vec4f::setW(float x) { this->_values[3] = x; }
void Vec4f::setR(float x) { this->_values[0] = x; }
void Vec4f::setG(float x) { this->_values[1] = x; }
void Vec4f::setB(float x) { this->_values[2] = x; }
void Vec4f::setA(float x) { this->_values[3] = x; }

float * Vec4f::getXYZW() const {
	static float res[NB_VALUES];
	std::copy(this->_values, this->_values + NB_VALUES, res);
	return res;
}

float * Vec4f::getRGBA() const {
	return this->getXYZW();
}

void Vec4f::setXYZW(float * values)
{
	this->setX(values[0]);
	this->setY(values[1]);
	this->setZ(values[2]);
	this->setW(values[3]);
}


void Vec4f::setRGBA(float * values)
{
	this->setXYZW(values);
}

void Vec4f::setXYZW(float x, float y, float z, float w)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setW(w);
}

void Vec4f::setRGBA(float r, float g, float b, float a)
{
	this->setXYZW(r, g, b, a);
}

float Vec4f::operator() (int index) const
{
	return this->_values[index];
}

Vec4f Vec4f::operator= (const Vec4f& rhs)
{
	//this->setXYZW(rhs.getXYZW());
	return *this;
}

Vec4f Vec4f::operator+ (const Vec4f& rhs) const
{
	float values[NB_VALUES];
	for(int i = 0; i < NB_VALUES; ++i)
	{
		values[i] = this->_values[i] + rhs._values[i];
	}
	return Vec4f(values);
}

Vec4f Vec4f::operator+= (const Vec4f& rhs)
{
	for(int i = 0; i < NB_VALUES; ++i)
	{
		this->_values[i] += rhs._values[i];
	}
	return *this;
}

float Vec4f::operator* (float rhs) const
{
	return this->getX() * rhs + this->getY() * rhs + this->getZ() * rhs + this->getW() * rhs;
}

float Vec4f::operator* (const Vec4f& rhs) const
{
	return this->getX() * rhs.getX() + this->getY() * rhs.getY() + this->getZ() * rhs.getZ() + this->getW() * rhs.getW();
}

Vec4f Vec4f::operator* (const Mat4f& rhs) const
{
	float x = rhs.getI() * *this;
	float y = rhs.getJ() * *this;
	float z = rhs.getK() * *this;
	float w = rhs.getT() * *this;

	return Vec4f(x, y, z, w);
}

std::ostream& operator<< (std::ostream& os, const Vec4f& v)
{
	os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ", " << v.getW() << ")";
	return os;
}