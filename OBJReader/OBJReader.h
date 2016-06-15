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
	/**
	* Klasa stanowi¹ca interfejs DLL
	*/
	class OBJReader
	{
	public:

		OBJReader();
		~OBJReader();

		/**
		* Metoda g³ówna, s³u¿¹ca do pobrania danych z pliku .OBJ
		* @param filename Œcie¿ka do pliku .OBJ
		* @return Kontener obiektów odpowiadaj¹cych powierzchniom teksturowanym obiektu z pliku .OBJ
		*/
		static OBJREADER_API std::vector<GeometryData*> getGeometryData(const char* filename);

	private:

	};
}
