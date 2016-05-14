#include "stdafx.h"
#include "OBJFileParser.h"

std::vector<OBJData*> OBJFileParser::Objects;

OBJFileParser::OBJFileParser()
{
}


OBJFileParser::~OBJFileParser()
{
}

void OBJFileParser::ReadFile(std::string filepath)
{
	std::ifstream file(filepath);
	std::string line, keyword;
	int lineNumber = 0;
	OBJData* objectData = nullptr; // zmienic na wskaznik i new ??
	//OBJData* currentObjectData = nullptr;

	if (file.is_open())
	{
		//objectData = new OBJData();

		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			lineNumber++;

			double vx, vy, vz;
			std::string objName;

			if (iss.peek() == EOF || iss.peek() == ' ') continue; // blank line
			if (iss.peek() == '#') continue; // test comment
			if (!(iss >> keyword))
			{
				throw "Error reading file at line: " + std::to_string(lineNumber);
				//if (keyword[0] == '#') continue; // ignore empty lines & comments)
				//std::cerr << "Error reading file: " << filepath << std::endl; // make exception out of it!
				break;
			} // error or blank line - TO check

			if (keyword[0] == 'o' || keyword[0] == 'g')
			{
				if (!(iss >> objName))
				{
					throw "Error parsing object name at line: " + lineNumber;
				}
				if (objectData != nullptr)
				{
					OBJFileParser::Objects.push_back(objectData);
				}
				objectData = new OBJData();
				objectData->Name = objName;

			}
			else if (keyword[0] == 'v')
			{
				if (keyword[1] == 't')
				{
					if (!(iss >> vx >> vy)) { throw "Error parsing vertice at line: " + lineNumber; }
					glm::vec2 v = { vx,vy };
					OBJData::FileTextureVertices.push_back(v);
				}
				else
				{
					if (!(iss >> vx >> vy >> vz)) { throw "Error parsing vertice at line: " + lineNumber; }
					glm::vec3 v = { vx,vy,vz };

					if (keyword[1] == NULL)
					{
						OBJData::FileVertices.push_back(v);
					}
					else if (keyword[1] == 'n')
					{
						OBJData::FileNormalVertices.push_back(v);
					}
					else
					{
						throw ("Error - unrecognized keyword: " + keyword + " at line: " + std::to_string(lineNumber)).c_str();
					}
				}
			}
			else if (keyword[0] == 'f')
			{
				FaceN f;

				int iv, ivn, ivt;
				if (!(iss >> iv))
				{
					throw "Error parsing face at line: " + lineNumber;
				}

				f.VertexIndices.push_back(iv);

				if (iss.peek() == '/')
				{
					//f.HasNormalVertices = true;
					iss.ignore();

					if (iss.peek() != '/') // texture v
					{
						if (!(iss >> ivt)) throw "Error parsing face at line: " + lineNumber;
						f.HasTextureVertices = true; // no consitency! must affect following reads

						f.TextureIndices.push_back(ivt);

						if (iss.peek() != '/') break; // v/t
					}
					// v//n or v/t/n
					iss.ignore();
					if (!(iss >> ivn)) throw "Error parsing face at line: " + lineNumber; // normal v
					f.HasNormalVertices = true;

					f.NormalIndices.push_back(ivn);
				}

				while (iss.peek() != EOF)
				{
					if (!(iss >> iv)) break;
					f.VertexIndices.push_back(iv);
					iss.ignore(); // first / or space
					if (f.HasTextureVertices)
					{
						if (!(iss >> ivt)) break;
						f.TextureIndices.push_back(ivt);
					}
					if (f.HasNormalVertices)
					{
						iss.ignore(); // second /
						if (!(iss >> ivn)) break;
						f.NormalIndices.push_back(ivn);
					}
				}

				objectData->Faces.push_back(f);
			}
		}
	}
	else
	{
		throw "Error opening file";
	}

	OBJFileParser::Objects.push_back(objectData);
	//return objectData;
}

std::vector<GeometryData*> OBJFileParser::GetTriangualizedObjects()
{
	//if (OBJFileParser::Objects.empty());
		return std::vector<GeometryData*>();
		
	// TO DO

}
