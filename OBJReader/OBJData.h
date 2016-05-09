#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>

struct Face3;

class OBJData
{
public:
	std::string Name;

	bool HasTextureVertices;
	bool HasNormalVertices; // change to bitmask?

	std::vector<glm::vec3> Vertices;
	std::vector<glm::vec3> NormalVertices;
	std::vector<glm::vec2> TextureVertices;

	std::vector<Face3> Faces;

	OBJData();
	~OBJData();

private:

};