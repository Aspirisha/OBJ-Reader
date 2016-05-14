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
	//s = "res\\cube.obj";
	cout << "OBJ 1:" << endl;
	OBJData* o1;
	o1 = OBJReaderDLL::OBJReader::getOBJ(s.c_str());

	if (o1 == nullptr)
	{
		cout << "Blad" << endl;
	}
	else
	{

		cout << o1->Name << endl;
		// cannot access static member from here
		//cout << OBJData::FileVertices[1].x << endl;
		//for (auto var : o1->FileVertices)
		//{
		//	cout << "V: " << var.x << ', ' << var.y << ', ' << var.z << endl;
		//}

		for (auto var : o1->Faces)
		{
			cout << "F: ";
			for (auto vi : var.VertexIndices)
			{
				cout << vi << ", ";
			}
			cout << endl;

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

