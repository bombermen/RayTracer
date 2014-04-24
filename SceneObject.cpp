#include "SceneObject.hpp"


SceneObject::SceneObject(void)
{
	this->_localMatrix = Mat4f::identity();
}

Mat4f SceneObject::getLocalMatrix() const
{
	return this->_localMatrix;
}

Mat4f SceneObject::getWorldMatrix() const
{
	return Mat4f();
}

Vec4f SceneObject::getColor() const
{
	return this->_color;
}

SceneObject * SceneObject::getParent() const
{
	return this->_parent;
}

std::vector<SceneObject> SceneObject::getChildren() const
{
	return this->_children;
}

void SceneObject::setLocalMatrix(Mat4f matrix)
{
	this->_localMatrix = matrix;
}

void SceneObject::setColor(Vec4f color)
{
	this->_color = color;
}

void SceneObject::setParent(SceneObject * parent)
{
	this->_parent = parent;
}

void SceneObject::translate(const Vec4f& translation)
{
	Vec4f t = this->_localMatrix.getT();
	this->_localMatrix.setT(t + translation);
	this->_localMatrix.setValueAt(1, 3, 3);
}

void SceneObject::scale(float s)
{
	this->_localMatrix *= s;
	this->_localMatrix.setValueAt(1, 3, 3);
}

void SceneObject::scale(Vec4f s)
{
	this->_localMatrix *= s;
	this->_localMatrix.setValueAt(1, 3, 3);
}