// OBJReader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OBJReader.h"

namespace OBJReaderDLL
{
	OBJReader::OBJReader()
	{
		
	}

	OBJReader::~OBJReader()
	{
	}

	std::vector<GeometryData*> OBJReader::getGeometryData(const char* filename)
	{
		std::vector<GeometryData*> gds;
		try
		{
			OBJFileParser::ReadFile(filename);
			gds = OBJFileParser::GetTriangualizedObjects();
		}
		catch (const char* ex)
		{
			std::cerr << ex << std::endl;
		}
		catch (std::string ex)
		{
			std::cerr << ex << std::endl;
		}
		return gds;
	}
}
