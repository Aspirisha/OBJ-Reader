// OBJReader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OBJReader.h"

namespace OBJReaderDLL
{
	int OBJReader::Test(int a, int b)
	{
		return a + b;
	}
	void OBJReader::ReadFile(std::string filepath)
	{
		std::ifstream file(filepath);
		std::string line;

		if (file.is_open())
			std::cout << "idziemy na otwarcie" << std::endl;
		else
			std::cout << "nie idziemy" << std::endl;

		//std::ofstream fdup("parasol.txt");
		
		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			char keyword;
			double vx, vy, vz;
			int f1, f2, f3;
			std::string objName;

			if (!(iss >> keyword)) { continue; } // error or blank line - TO check

			if (keyword == 'g')
			{
				if (!(iss >> objName)) { break; }
				std::cout << "Nazwa obiektu: " << objName << std::endl;
			}
			else if (keyword == 'v')
			{
				if (!(iss >> vx >> vy >> vz)) { break; }
				std::cout << "Wierzcholek: " << vx << ", " << vy << ", " << vz << std::endl;
			}
			else if (keyword == 'f')
			{
				if (!(iss >> f1 >> f2 >> f3)) { break; }
				std::cout << "Fejs: " << f1 << ", " << f2 << ", " << f3 << std::endl;
			}
		}
	}
}
