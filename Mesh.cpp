#include "Mesh.hpp"

Mesh::Mesh() { }

//getters
std::vector<Vec4f> Mesh::getVertices() const
{
	return this->_vertices;
}

std::vector<std::vector<unsigned int>> Mesh::getFaces() const
{
	return this->_faces;
}

std::vector<Vec4f> Mesh::getNormals() const
{
	return this->_normals;
}


//setters
void Mesh::setVertices(const std::vector<Vec4f>& vertices)
{
	this->_vertices = vertices;
}

void Mesh::setFaces(const std::vector<std::vector<unsigned int>>& faces)
{
	this->_faces = faces;
}

void Mesh::setNormals(const std::vector<Vec4f>& normals)
{
	this->_normals = normals;
}

