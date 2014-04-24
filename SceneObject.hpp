#pragma once

#include "Mat4f.hpp"
#include <vector>

class SceneObject
{
public:
	SceneObject(void);

	//getters/setters
	Mat4f getLocalMatrix() const;
	Mat4f getWorldMatrix() const;
	Vec4f getColor() const;
	SceneObject * getParent() const;
	std::vector<SceneObject> getChildren() const;

	void setLocalMatrix(Mat4f matrix);
	void setColor(Vec4f color);
	void setParent(SceneObject * parent);

	void translate(const Vec4f& t);
	void scale(float s);
	void scale(Vec4f s);
	//void rotate();

private:
	Mat4f _localMatrix;
	Vec4f _color;
	SceneObject * _parent;
	std::vector<SceneObject> _children;
	//Material _material;
};

