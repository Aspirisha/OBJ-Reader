#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include "OBJData.h"
#include "GeometryData.h"

/**
* Klasa s�u��ca do parsowania i wczytywania danych z plik�w .OBJ
*/
class OBJFileParser
{
public:

	OBJFileParser();
	~OBJFileParser();

	/**
	* Metoda parsuj�ca plik i wst�pnie �aduj�ca dane do pami�ci
	* @param filename �cie�ka do pliku .OBJ
	*/
	static void ReadFile(std::string filepath);
	/**
	* Metoda przetwarzaj�ca za�adowane dane na teksturowane obiekty o tr�jk�tnej siatce
	* @return Kontener obiekt�w odpowiadaj�cych powierzchniom teksturowanym obiektu z pliku .OBJ
	*/
	static std::vector<GeometryData*> GetTriangualizedObjects();
private:
	static std::vector<OBJData*> Objects;
};
