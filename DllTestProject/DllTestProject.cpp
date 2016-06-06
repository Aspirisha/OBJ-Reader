// DllTestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "OBJReader.h"

using namespace std;

void Read(string s)
{
	vector<GeometryData*> objects = OBJReaderDLL::OBJReader::getGeometryData(s.c_str());

	if (objects.empty())
	{
		cout << "Blad" << endl;
	}
	else
	{
		for (auto ob : objects)
		{
			cout << "\tTekstura obiektu: " << ob->Material << endl;
			int faceNumber = 0;
			for (auto var : ob->TriangleMesh)
			{
				cout << "Fejs " << ++faceNumber << ":" << endl;
				//cout << "Wspolrzedne wiercholkow: ";
				for (int i = 0; i < 3; i++)
					cout << "V" << i + 1 << " (" << var.VertexCoords[i].x << ", " << var.VertexCoords[i].y << ", " << var.VertexCoords[i].z << "), ";
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
}

int main()
{
	vector<string> s;
	s.push_back( "res\\diamond.obj");
	s.push_back("res\\cube no tx.obj");
	s.push_back("res\\cube.obj");
	s.push_back("res\\cube multi material.obj");
	s.push_back("res\\negative.obj");
	s.push_back("res\\capsule.obj"); // big
	s.push_back("res\\beretta magazine.obj");
	s.push_back("res\\skyscraper.obj");

	int input;
	while (true)
	{
		cout << "e - wyjscie, nr plikow: " << endl;
		for (int i = 0; i < s.size(); i++)
		{
			cout << i + 1 << " - " << s[i] << endl;
		}
		input = 0;
		cin >> input;
		if (input < 1 || input > s.size()) break;
		else
		{
			cout << "Dane odczytane z pliku OBJ: " << s[input - 1] << endl;
			Read(s[input - 1]);
		}
	}

	return 0;
}

