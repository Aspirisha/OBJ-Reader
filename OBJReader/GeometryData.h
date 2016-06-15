#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>

/**
* Struktura przechowuj¹ca wspó³rzêdne wierzcho³ków sk³adaj¹cych siê na pojedynczy, trójk¹tny element siatki obiektu geometrycznego
*/
struct Face3
{
	glm::vec3 VertexCoords[3] /** Tablica wspó³rzêdnych trzech zwyk³ych wierzcho³ków */, NormalCoords[3] /** Tablica wspó³rzêdnych trzech normalnych */;
	glm::vec2 TextureCoords[3]; /**< Tablica wspó³rzêdnych trzech wierzcho³ków dla tekstur */
};

/**
* Klasa reprezentuj¹ca obiekty podzielone wg u¿ywanych tekstur oraz zbudowanej z siatki wy³¹cznie trójk¹tnych elementów
*/
class GeometryData
{
public:
	/**
	* Nazwa materia³u u¿ywanego przez obiekt
	*/
	std::string Material;

	/**
	* Flaga informuj¹ca czy obiekt zawiera wierzcho³ki dla tekstur
	*/
	bool HasTextureVertices = false;

	/**
	* Flaga informuj¹ca czy obiekt zawiera normalne
	*/
	bool HasNormalVertices = false;

	/**
	* Kontener reprezentuj¹cy siatkê (mesh) obiektu za pomoc¹ elementów trójk¹tnych
	*/
	std::vector<Face3> TriangleMesh;

	GeometryData();
	~GeometryData();
};
