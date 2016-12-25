#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

/**
* Struktura przechowuj�ca dane element�w typu Face o dowolnej liczbie wierzcho�k�w.
* Elementy typu Face definiuj� po��czenia mi�dzy wierzcho�kami sk�adaj�cymi si� na obiekt.
*/
struct FaceN
{
	/**
	* Flaga informuj�ca czy element zawiera wierzcho�ki dla tekstur
	*/
	bool HasTextureVertices = false;
	/**
	* Flaga informuj�ca czy element zawiera normalne
	*/
	bool HasNormalVertices = false;

	/**
	* Kontener przechowuj�cy wsp�rz�dne zwyk�ych wierzcho�k�w sk�adaj�cych si� na element
	*/
	std::vector<int> VertexIndices;
	/**
	* Kontener przechowuj�cy wsp�rz�dne normalnych sk�adaj�cych si� na element
	*/
	std::vector<int> NormalIndices;
	/**
	* Kontener przechowuj�cy wsp�rz�dne wierzcho�k�w dla tekstur sk�adaj�cych si� na element
	*/
	std::vector<int> TextureIndices;
};

/**
* Klasa reprezentuj�ca obiekty podzielone wg u�ywanych tekstur, wczytane bezpo�rednio z pliku .OBJ 
*/
class OBJData
{
public:
	/**
	* Kontener przechowuj�cy list� wszytykich zwyk�ych wierzcho�k�w w danym pliku
	*/
	static std::vector<glm::vec3> FileVertices;
	/**
	* Kontener przechowuj�cy list� wszytykich normalnych w danym pliku
	*/
	static std::vector<glm::vec3> FileNormalVertices;
	/**
	* Kontener przechowuj�cy list� wszytykich wierzcho�k�w dla tekstur w danym pliku
	*/
	static std::vector<glm::vec2> FileTextureVertices;

	/**
	* Nazwa obiektu
	*/
	static std::string Name;
	/**
	* Nazwa pliku zawieraj�cego definicje materia��w (tekstur)
	*/
	static std::string MaterialLibrary;

	/**
	* Nazwa materia�u u�ywanego przez obiekt
	*/
	std::string Material;
	/**
	* Kontener reprezentuj�cy siatk� (mesh) obiektu za pomoc� element�w typu Face
	*/
	std::vector<FaceN> Faces;

	OBJData();
	~OBJData();


private:

};

