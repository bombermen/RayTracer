#pragma once

#include "Vec4f"

class Mesh
{
public:
	Mesh();

	//getters
	std::vector<Vec4f> getVertices() const;
	std::vector<unsigned int[3]> getFaces() const;
	std::vector<Vec4f> getNormals() const;

	//setters
	void setVertices(const std::vector<Vec4f>& vertices);
	void setFaces(const std::vector<unsigned int[3]>& faces);
	void setNormals(const std::vector<Vec4f>& normals);

private:
	std::vector<Vec4f> _vertices;
	std::vector<unsigned int[3]> _faces;
	std::vector<Vec4f> _normals;
};
