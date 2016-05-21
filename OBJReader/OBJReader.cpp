// OBJReader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OBJReader.h"

namespace OBJReaderDLL
{
	OBJReader::OBJReader()
	{
		
	}

	OBJReader::~OBJReader()
	{
	}

	OBJData* OBJReader::getOBJ(const char* filename)
	{
		OBJData* o = nullptr;
		try
		{
			OBJFileParser::ReadFile(filename);
			o = OBJFileParser::Objects.front();
		}
		catch (const char* ex)
		{
			std::cerr << ex << std::endl;
		}
		catch (std::string ex)
		{
			std::cerr << ex << std::endl;
		}
		return o;
	}

	std::vector<GeometryData*> OBJReader::getGeometryData(const char* filename)
	{
		std::vector<GeometryData*> gds;
		try
		{
			OBJFileParser::ReadFile(filename);
			gds = OBJFileParser::GetTriangualizedObjects();
		}
		catch (const char* ex)
		{
			std::cerr << ex << std::endl;
		}
		catch (std::string ex)
		{
			std::cerr << ex << std::endl;
		}
		return gds;
	}

	struct Face
	{
		bool HasTextureVertices = false;
		bool HasNormalVertices = false;
		int v[3], vn[3], vt[3];
	};

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
			std::string keyword;
			//char keyword[2]; // string albo czytanie max 2 znaki (nie przez >>) - problem dla roznej ilosci bialych znakow
			//iss.read(keyword, 2);
			double vx, vy, vz;
			//int f1, f2, f3;
			std::string objName;


			if (!(iss >> keyword))
			{
				if (keyword[0] == NULL || keyword[0] == '#') continue; // ignore empty lines & comments)
				std::cerr << "Error reading file: " << filepath << std::endl; // make exception out of it!
				break;
			} // error or blank line - TO check

			if (keyword[0] == 'g')
			{
				if (!(iss >> objName)) { break; }
				std::cout << "Nazwa obiektu: " << objName << std::endl;
			}
			else if (keyword[0] == 'v')
			{
				if (keyword[1] == NULL)
				{
					if (!(iss >> vx >> vy >> vz)) { break; }
					std::cout << "Wierzcholek: " << std::fixed << vx << ", " << vy << ", " << vz << std::endl;
				}
				else if (keyword[1] == 'n')
				{
					if (!(iss >> vx >> vy >> vz)) { break; }
					std::cout << "Normalna: " << vx << ", " << vy << ", " << vz << std::endl;
				}
				else if (keyword[1] == 't')
				{
					if (!(iss >> vx >> vy)) { break; }
					std::cout << "Tekstura: " << vx << ", " << vy << std::endl;
				}
				else
				{
					std::cerr << "Error - unrecognized keyword: v" << keyword[1] << std::endl; // throw exception now!
				}

			}
			else if (keyword[0] == 'f')
			{
				Face f;
				if (!(iss >> f.v[0]))
				{
					break; // ex
				}
				if (iss.peek() == '/')
				{
					f.HasNormalVertices = true;
					iss.ignore();

					if (iss.peek() != '/') // texture v
					{
						f.HasTextureVertices = true; // no consitency! must affect following reads
						if (!(iss >> f.vt[0])) break;
					}
					iss.ignore();
					if (!(iss >> f.vn[0])) break; // normal v

					for (int i = 1; i < 3; i++)
					{
						if (!(iss >> f.v[i])) break;
						iss.ignore();
						if (f.HasTextureVertices)
						{
							if (!(iss >> f.vt[i])) break;
						}
						iss.ignore();
						if (!(iss >> f.vn[i])) break;
					}
				}
				else
				{
					if (!(iss >> f.v[1] >> f.v[2])) break; // vertices only
				}
				
				if (f.HasNormalVertices)
				{
					if (f.HasTextureVertices)
					{
						for (int i = 0; i < 3; i++)
						{
							std::cout << "Siat ya Fejs: trojka nr " << i + 1 << " (v, text, norm) " << f.v[i] << ", " << f.vt[i] << ", " << f.vn[i] << std::endl;
						}
					}
					else
					{
						for (int i = 0; i < 3; i++)
						{
							std::cout << "Siat ya Fejs: dwojka nr " << i + 1 << " (v, norm) " << f.v[i] << ", " << f.vn[i] << std::endl;
						}
					}
				}
				else
				{
					std::cout << "Siat ya Fejs: " << f.v[0] << ", " << f.v[1] << ", " << f.v[2] << std::endl;
				}
				
			}
		}
	}
}
