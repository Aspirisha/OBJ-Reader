#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>

//struct Face3
//{
//	glm::vec3 Vertices, NormalVertices;
//	glm::vec2 TextureVertices;
//};

//struct Face3
//{
//	bool HasTextureVertices = false;
//	bool HasNormalVertices = false;
//
//	int VertexIndices[3];
//	int NormalIndices[3];
//	int TextureIndices[3];
//};

struct Face3
{
	glm::vec3 VertexCoords[3], NormalCoords[3];
	glm::vec2 TextureCoords[3];
};

class GeometryData
{
public:
	std::string Material;

	bool HasTextureVertices = false;
	bool HasNormalVertices = false; // change to bitmask?

	//std::vector<glm::vec3> Vertices;
	//std::vector<glm::vec3> NormalVertices;
	//std::vector<glm::vec2> TextureVertices;

	std::vector<Face3> TriangleMesh;

	GeometryData();
	~GeometryData();
};
