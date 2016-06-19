#pragma once

#include "libs/glm/vec2.hpp"
#include "libs/glm/vec3.hpp"
#include <vector>

/**
* Struktura przechowuj¹ca dane elementów typu Face o dowolnej liczbie wierzcho³ków.
* Elementy typu Face definiuj¹ po³¹czenia miêdzy wierzcho³kami sk³adaj¹cymi siê na obiekt.
*/
struct FaceN
{
	/**
	* Flaga informuj¹ca czy element zawiera wierzcho³ki dla tekstur
	*/
	bool HasTextureVertices = false;
	/**
	* Flaga informuj¹ca czy element zawiera normalne
	*/
	bool HasNormalVertices = false;

	/**
	* Kontener przechowuj¹cy wspó³rzêdne zwyk³ych wierzcho³ków sk³adaj¹cych siê na element
	*/
	std::vector<int> VertexIndices;
	/**
	* Kontener przechowuj¹cy wspó³rzêdne normalnych sk³adaj¹cych siê na element
	*/
	std::vector<int> NormalIndices;
	/**
	* Kontener przechowuj¹cy wspó³rzêdne wierzcho³ków dla tekstur sk³adaj¹cych siê na element
	*/
	std::vector<int> TextureIndices;
};

/**
* Klasa reprezentuj¹ca obiekty podzielone wg u¿ywanych tekstur, wczytane bezpoœrednio z pliku .OBJ 
*/
class OBJData
{
public:
	/**
	* Kontener przechowuj¹cy listê wszytykich zwyk³ych wierzcho³ków w danym pliku
	*/
	static std::vector<glm::vec3> FileVertices;
	/**
	* Kontener przechowuj¹cy listê wszytykich normalnych w danym pliku
	*/
	static std::vector<glm::vec3> FileNormalVertices;
	/**
	* Kontener przechowuj¹cy listê wszytykich wierzcho³ków dla tekstur w danym pliku
	*/
	static std::vector<glm::vec2> FileTextureVertices;

	/**
	* Nazwa obiektu
	*/
	static std::string Name;
	/**
	* Nazwa pliku zawieraj¹cego definicje materia³ów (tekstur)
	*/
	static std::string MaterialLibrary;

	/**
	* Nazwa materia³u u¿ywanego przez obiekt
	*/
	std::string Material;
	/**
	* Kontener reprezentuj¹cy siatkê (mesh) obiektu za pomoc¹ elementów typu Face
	*/
	std::vector<FaceN> Faces;

	OBJData();
	~OBJData();


private:

};

