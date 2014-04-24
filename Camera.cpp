#include "Camera.hpp"

Camera::Camera() { }

//getters
int Camera::getType() const
{
	return this->_type;
}

float Camera::getFocalLength() const
{
	return this->_focalLength;
}

float Camera::getNear() const
{
	return this->_near;
}

float Camera::getFar() const
{
	return this->_far;
}

float Camera::getWidth() const
{
	return this->_width;
}

float Camera::getHeight() const
{
	return this->_height;
}


//setters
void Camera::setType(int type)
{
	this->_type = type;
}

void Camera::setFocalLength(float focalLength)
{
	this->_focalLength = focalLength;
}

void Camera::setNear(float near)
{
	this->_near = near;
}

void Camera::setFar(float far)
{
	this->_far = far;
}

void Camera::setWidth(float width)
{
	this->_width = width;
}

void Camera::setHeight(float height)
{
	this->_height = height;
}

