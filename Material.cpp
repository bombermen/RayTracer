#include "Material.hpp"

Material::Material() { }

//getters
Vec4f Material::getAmbient() const
{
	return this->_ambient;
}

Vec4f Material::getDiffuse() const
{
	return this->_diffuse;
}

Vec4f Material::getSpecular() const
{
	return this->_specular;
}

float Material::getSpecularAngle() const
{
	return this->_specularAngle;
}

float Material::getIor() const
{
	return this->_ior;
}

bool Material::isTransparent() const
{
	return this->_transparent;
}

float Material::getTransparency() const
{
	return this->_transparency;
}

float Material::getTransparencyDepth() const
{
	return this->_transparencyDepth;
}

bool Material::isReflective() const
{
	return this->_reflective;
}

float Material::getReflectivity() const
{
	return this->_reflectivity;
}

float Material::getReflectivityDepth() const
{
	return this->_reflectivityDepth;
}


//setters
void Material::setAmbient(const Vec4f& ambient)
{
	this->_ambient = ambient;
}

void Material::setDiffuse(const Vec4f& diffuse)
{
	this->_diffuse = diffuse;
}

void Material::setSpecular(const Vec4f& specular)
{
	this->_specular = specular;
}

void Material::setSpecularAngle(float specularAngle)
{
	this->_specularAngle = specularAngle;
}

void Material::setIor(float ior)
{
	this->_ior = ior;
}

void Material::setTransparent(bool transparent)
{
	this->_transparent = transparent;
}

void Material::setTransparency(float transparency)
{
	this->_transparency = transparency;
}

void Material::setTransparencyDepth(float transparencyDepth)
{
	this->_transparencyDepth = transparencyDepth;
}

void Material::setReflective(bool reflective)
{
	this->_reflective = reflective;
}

void Material::setReflectivity(float reflectivity)
{
	this->_reflectivity = reflectivity;
}

void Material::setReflectivityDepth(float reflectivityDepth)
{
	this->_reflectivityDepth = reflectivityDepth;
}

