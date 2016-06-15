#include "stdafx.h"
#include "OBJData.h"


std::vector<glm::vec3> OBJData::FileVertices;
std::vector<glm::vec3> OBJData::FileNormalVertices;
std::vector<glm::vec2> OBJData::FileTextureVertices;

std::string OBJData::Name;
std::string OBJData::MaterialLibrary;

OBJData::OBJData()
{
}
