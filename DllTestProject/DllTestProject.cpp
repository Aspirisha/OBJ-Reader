// DllTestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "OBJReader.h"

using namespace std;

int main()
{
	int a = 2;
	int b = 3;

	cout << "a + b = "
		<< OBJReaderDLL::OBJReader::Test(a, b)
		<< endl;

	string s = "res\\diamond.obj";
	s = "res\\cube no tx.obj";
	s = "res\\cube.obj";
	s = "res\\cube multi material.obj";


	cout << "OBJ Test" << endl;
	vector<GeometryData*> objects = OBJReaderDLL::OBJReader::getGeometryData(s.c_str());

	if (objects.empty())
	{
		cout << "Blad" << endl;
	}
	else
	{
		for (auto ob : objects)
		{
			cout << "Tekstura obiektu: " << ob->Material << endl;
			int faceNumber = 0;
			for (auto var : ob->TriangleMesh)
			{
				cout << "Fejs " << ++faceNumber << ":" << endl;
				//cout << "Wspolrzedne wiercholkow: ";
				for (int i = 0; i < 3; i++)
					cout << "V" << i+1 << " (" << var.VertexCoords[i].x << ", " << var.VertexCoords[i].y << ", " << var.VertexCoords[i].z << "), ";
				cout << endl;

				if (ob->HasNormalVertices)
				{
					//cout << "Wspolrzedne wiercholkow (normalne): ";
					for (int i = 0; i < 3; i++)
						cout << "VN" << i + 1 << " (" << var.NormalCoords[i].x << ", " << var.NormalCoords[i].y << ", " << var.NormalCoords[i].z << "), ";
					cout << endl;
				}
				if (ob->HasTextureVertices)
				{
					//cout << "Wspolrzedne wiercholkow (tekstura): ";
					for (int i = 0; i < 3; i++)
						cout << "VT" << i + 1 << " (" << var.TextureCoords[i].x << ", " << var.TextureCoords[i].y << "), ";
					cout << endl;
				}
			}
		}


	}

	//s = "res\\cube no tx.obj";
	//cout << "OBJ 2:" << endl;
	//OBJReaderDLL::OBJReader::ReadFile(s);

	//s = "res\\cube.obj";
	//cout << "OBJ 3:" << endl;
	//OBJReaderDLL::OBJReader::ReadFile(s);

	cin.get();

    return 0;
}

