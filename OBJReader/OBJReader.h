#pragma once

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
		static std::vector<GeometryData*> getGeometryData(const char* filename);

	private:

	};
}
