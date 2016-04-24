#pragma once

#ifdef OBJREADER_EXPORTS
#define OBJREADER_API __declspec(dllexport)
#else
#define OBJREADER_API __declspec(dllimport)
#endif

namespace OBJReaderDLL
{
	class OBJReader
	{
	public:
		OBJReader();
		~OBJReader();
		static OBJREADER_API int Test(int a, int b);

	private:

	};

	OBJReader::OBJReader()
	{
	}

	OBJReader::~OBJReader()
	{
	}
}