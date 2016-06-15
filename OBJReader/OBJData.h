#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>

struct FaceN
{
	bool HasTextureVertices = false;
	bool HasNormalVertices = false;

	std::vector<int> VertexIndices;
	std::vector<int> NormalIndices;
	std::vector<int> TextureIndices;
};

class OBJData
{
public:
	static std::vector<glm::vec3> FileVertices;
	static std::vector<glm::vec3> FileNormalVertices;
	static std::vector<glm::vec2> FileTextureVertices;

	static std::string Name;
	static std::string MaterialLibrary;

	std::string Material;
	std::vector<FaceN> Faces;

	OBJData();
	~OBJData();


private:

};

