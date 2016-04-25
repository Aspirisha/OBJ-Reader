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

namespace OBJReaderDLL
{
	class OBJReader
	{
	public:
		OBJReader();
		~OBJReader();
		static OBJREADER_API int Test(int a, int b);
		static OBJREADER_API void ReadFile(std::string filepath);

	private:

	};

	OBJReader::OBJReader()
	{
	}

	OBJReader::~OBJReader()
	{
	}
}