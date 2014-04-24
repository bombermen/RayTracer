#pragma once

#include "Vec4f.hpp"

class Material
{
public:
	Material();

	//getters
	Vec4f getAmbient() const;
	Vec4f getDiffuse() const;
	Vec4f getSpecular() const;
	float getSpecularAngle() const;
	float getIor() const;
	bool isTransparent() const;
	float getTransparency() const;
	float getTransparencyDepth() const;
	bool isReflective() const;
	float getReflectivity() const;
	float getReflectivityDepth() const;

	//setters
	void setAmbient(const Vec4f& ambient);
	void setDiffuse(const Vec4f& diffuse);
	void setSpecular(const Vec4f& specular);
	void setSpecularAngle(float specularAngle);
	void setIor(float ior);
	void setTransparent(bool transparent);
	void setTransparency(float transparency);
	void setTransparencyDepth(float transparencyDepth);
	void setReflective(bool reflective);
	void setReflectivity(float reflectivity);
	void setReflectivityDepth(float reflectivityDepth);

private:
	Vec4f _ambient;
	Vec4f _diffuse;
	Vec4f _specular;
	float _specularAngle;
	float _ior;
	bool _transparent;
	float _transparency;
	float _transparencyDepth;
	bool _reflective;
	float _reflectivity;
	float _reflectivityDepth;
};
