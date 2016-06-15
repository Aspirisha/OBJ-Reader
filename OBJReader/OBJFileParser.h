#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include "OBJData.h"
#include "GeometryData.h"

/**
* Klasa s³u¿¹ca do parsowania i wczytywania danych z plików .OBJ
*/
class OBJFileParser
{
public:

	OBJFileParser();
	~OBJFileParser();

	/**
	* Metoda parsuj¹ca plik i wstêpnie ³aduj¹ca dane do pamiêci
	* @param filename Œcie¿ka do pliku .OBJ
	*/
	static void ReadFile(std::string filepath);
	/**
	* Metoda przetwarzaj¹ca za³adowane dane na teksturowane obiekty o trójk¹tnej siatce
	* @return Kontener obiektów odpowiadaj¹cych powierzchniom teksturowanym obiektu z pliku .OBJ
	*/
	static std::vector<GeometryData*> GetTriangualizedObjects();
private:
	static std::vector<OBJData*> Objects;
};
