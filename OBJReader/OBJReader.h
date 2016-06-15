#pragma once

#ifdef OBJREADER_EXPORTS
#define OBJREADER_API __declspec(dllexport)
#else
#define OBJREADER_API __declspec(dllimport)
#endif

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "OBJData.h"
#include "OBJFileParser.h"

namespace OBJReaderDLL
{
	class OBJReader
	{
	public:

		OBJReader();
		~OBJReader();

		static OBJREADER_API std::vector<GeometryData*> getGeometryData(const char* filename);

	private:

	};
}
