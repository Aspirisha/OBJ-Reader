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
	* Klasa stanowi�ca interfejs DLL
	*/
	class OBJReader
	{
	public:

		OBJReader();
		~OBJReader();

		/**
		* Metoda g��wna, s�u��ca do pobrania danych z pliku .OBJ
		* @param filename �cie�ka do pliku .OBJ
		* @return Kontener obiekt�w odpowiadaj�cych powierzchniom teksturowanym obiektu z pliku .OBJ
		*/
		static OBJREADER_API std::vector<GeometryData*> getGeometryData(const char* filename);

	private:

	};
}
