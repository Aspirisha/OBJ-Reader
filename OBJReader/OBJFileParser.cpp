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
	std::string line, keyword, material, materialLib;
	int lineNumber = 0;
	OBJData* objectData = nullptr;

	if (file.is_open())
	{
		OBJFileParser::Objects.clear();
		OBJData::FileVertices.clear();
		OBJData::FileNormalVertices.clear();
		OBJData::FileTextureVertices.clear();

		OBJData::Name.clear();
		OBJData::MaterialLibrary.clear();

		objectData = new OBJData();

		while (std::getline(file, line))
		{
			if (line.empty()) continue; // blank line
			std::istringstream iss(line);
			lineNumber++;

			double vx, vy, vz;
			std::string objName;

			if (!(iss >> keyword))
			{
				if (line[0] == ' ') continue;
				throw "Error reading file at line: " + std::to_string(lineNumber);
				break;
			}
			else if (keyword[0] == '#') continue; // ignore comments
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
			else if (keyword[0] == 'f') // todo: change indexes here
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
						f.HasTextureVertices = true; // no consitency! should (?) affect following reads

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
			else if (keyword == "usemtl")
			{
				if (!(iss >> material)) throw "Error parsing material name at line: " + lineNumber;
				if (!objectData->Material.empty())
				{
					OBJFileParser::Objects.push_back(objectData);
				}
				objectData = new OBJData();
				objectData->Material = material;
			}
			else if (keyword[0] == 'o')
			{
				if (!(iss >> objName))
				{
					throw "Error parsing object name at line: " + lineNumber;
				}
				OBJData::Name = objName;

			}
			else if (keyword == "mtlib")
			{
				if (!(iss >> materialLib)) throw "Error parsing mtlib at line: " + lineNumber;
				OBJData::MaterialLibrary = materialLib;
			}
		}
	}
	else
	{
		throw "Error opening file";
	}

	OBJFileParser::Objects.push_back(objectData);
}

std::vector<GeometryData*> OBJFileParser::GetTriangualizedObjects()
{
	if (OBJFileParser::Objects.empty()) return std::vector<GeometryData*>();

	std::vector<GeometryData*> geoDatavec;

	for (auto obj : OBJFileParser::Objects)
	{
		GeometryData* gd;
		gd = new GeometryData();
		if (!obj->Material.empty())
		{
			gd->Material = obj->Material;
		}

		for (auto face : obj->Faces)
		{
			//gd.Faces = TriangulateFace(face);
			for (unsigned int i = 2; i < face.VertexIndices.size(); i++)
			{
				Face3 f3;
				f3.VertexCoords[0] = obj->FileVertices[face.VertexIndices[0] - 1]; // -1 for .obj file indexes
				f3.VertexCoords[1] = obj->FileVertices[face.VertexIndices[i - 1] - 1];
				f3.VertexCoords[2] = obj->FileVertices[face.VertexIndices[i] - 1];

				if (face.HasTextureVertices)
				{
					gd->HasTextureVertices = true;
					f3.TextureCoords[0] = obj->FileTextureVertices[face.TextureIndices[0] - 1];
					f3.TextureCoords[1] = obj->FileTextureVertices[face.TextureIndices[i - 1] - 1];
					f3.TextureCoords[2] = obj->FileTextureVertices[face.TextureIndices[i] - 1];
				}
				if (face.HasNormalVertices)
				{
					gd->HasNormalVertices = true;
					f3.NormalCoords[0] = obj->FileNormalVertices[face.NormalIndices[0] - 1];
					f3.NormalCoords[1] = obj->FileNormalVertices[face.NormalIndices[i - 1] - 1];
					f3.NormalCoords[2] = obj->FileNormalVertices[face.NormalIndices[i] - 1];
				}

				gd->TriangleMesh.push_back(f3);
			}
		}
		geoDatavec.push_back(gd);
	}

	return geoDatavec;
}
