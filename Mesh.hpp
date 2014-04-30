#pragma once

#include "Vec4f.hpp"

class Mesh
{
public:
	Mesh();

	//getters
	std::vector<Vec4f> getVertices() const;
	std::vector<std::vector<unsigned int>> getFaces() const;
	std::vector<Vec4f> getNormals() const;

	//setters
	void setVertices(const std::vector<Vec4f>& vertices);
	void setFaces(const std::vector<std::vector<unsigned int>>& faces);
	void setNormals(const std::vector<Vec4f>& normals);

private:
	std::vector<Vec4f> _vertices;
	std::vector<std::vector<unsigned int>> _faces;
	std::vector<Vec4f> _normals;
};
