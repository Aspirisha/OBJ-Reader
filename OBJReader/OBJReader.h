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

namespace OBJReaderDLL
{
	class OBJReader
	{
	public:
		//static std::string TestString;

		OBJReader();
		~OBJReader();
		static OBJREADER_API int Test(int a, int b);
		static OBJREADER_API void ReadFile(std::string filepath);
		static OBJREADER_API std::string GetString();

		// factory?
		static OBJREADER_API OBJData* getOBJ();

	private:

	};
}