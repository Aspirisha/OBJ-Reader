#include "stdafx.h"
#include "OBJData.h"


std::vector<glm::vec3> OBJData::FileVertices;
std::vector<glm::vec3> OBJData::FileNormalVertices;
std::vector<glm::vec2> OBJData::FileTextureVertices;

std::vector<glm::vec3> OBJData::GetFileVertices()
{
	return OBJData::FileVertices;
}

OBJData::OBJData()
{
	//Vertices[1].
}