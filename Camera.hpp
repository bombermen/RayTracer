#pragma once


class Camera
{
public:
	Camera();

	//getters
	int getType() const;
	float getFocalLength() const;
	float getNear() const;
	float getFar() const;
	float getWidth() const;
	float getHeight() const;

	//setters
	void setType(int type);
	void setFocalLength(float focalLength);
	void setNear(float near);
	void setFar(float far);
	void setWidth(float width);
	void setHeight(float height);

private:
	int _type;
	float _focalLength;
	float _near;
	float _far;
	float _width;
	float _height;
};
