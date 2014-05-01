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
	Vec4f i = this->_localMatrix.getI().multiply( s.getX() );
	Vec4f j = this->_localMatrix.getJ().multiply( s.getY() );
	Vec4f k = this->_localMatrix.getK().multiply( s.getZ() );
	
	this->_localMatrix.setI(i);
	this->_localMatrix.setJ(j);
	this->_localMatrix.setK(k);
}

void SceneObject::rotateX(float theta)
{
	float cosT = std::cos(theta);
	float sinT = std::sin(theta);

	float values[] =   {1    , 0    , 0    , 0    ,
						0    , cosT , -sinT, 0    ,
						0    , sinT ,  cosT, 0    ,
						0    , 0    ,  0   , 1    };

	Mat4f rotationMatrix(values);

	Mat4f rotated = this->_localMatrix * rotationMatrix;

	this->_localMatrix = rotated;
}

void SceneObject::rotateY(float theta)
{

}

void SceneObject::rotateZ(float theta)
{

}