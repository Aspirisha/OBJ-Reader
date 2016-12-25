#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>
#include <string>

/**
* Struktura przechowuj�ca wsp�rz�dne wierzcho�k�w sk�adaj�cych si� na pojedynczy, tr�jk�tny element siatki obiektu geometrycznego
*/
struct Face3
{
	glm::vec3 VertexCoords[3] /** Tablica wsp�rz�dnych trzech zwyk�ych wierzcho�k�w */, NormalCoords[3] /** Tablica wsp�rz�dnych trzech normalnych */;
	glm::vec2 TextureCoords[3]; /**< Tablica wsp�rz�dnych trzech wierzcho�k�w dla tekstur */
};

/**
* Klasa reprezentuj�ca obiekty podzielone wg u�ywanych tekstur oraz zbudowanej z siatki wy��cznie tr�jk�tnych element�w
*/
class GeometryData
{
public:
	/**
	* Nazwa materia�u u�ywanego przez obiekt
	*/
	std::string Material;

	/**
	* Nazwa pliku zawieraj�cego definicje materia��w
	*/
	std::string MaterialLibrary;

	/**
	* Flaga informuj�ca czy obiekt zawiera wierzcho�ki dla tekstur
	*/
	bool HasTextureVertices = false;

	/**
	* Flaga informuj�ca czy obiekt zawiera normalne
	*/
	bool HasNormalVertices = false;

	/**
	* Kontener reprezentuj�cy siatk� (mesh) obiektu za pomoc� element�w tr�jk�tnych
	*/
	std::vector<Face3> TriangleMesh;

	GeometryData();
	~GeometryData();
};
