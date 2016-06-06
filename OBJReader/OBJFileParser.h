#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include "OBJData.h"
#include "GeometryData.h"

class OBJFileParser
{
public:

	OBJFileParser();
	~OBJFileParser();

	static void ReadFile(std::string filepath);
	static std::vector<GeometryData*> GetTriangualizedObjects();
private:
	static std::vector<OBJData*> Objects;
};


