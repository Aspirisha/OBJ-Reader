
#include "OBJFileParser.h"

std::vector<OBJData*> OBJFileParser::Objects;

OBJFileParser::OBJFileParser()
{
}


OBJFileParser::~OBJFileParser()
{
}

inline void transformIndex(int &index)
{
	if (index > 0)
		index -= 1;
	else
		index += OBJData::FileVertices.size();
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
			else if (keyword[0] == 'f')
			{
				FaceN f;

				int indx;
				if (!(iss >> indx))
				{
					throw "Error parsing face at line: " + lineNumber;
				}

				transformIndex(indx);
				f.VertexIndices.push_back(indx);

				if (iss.peek() == '/') // check for first slash inh v/t OR v//n OR v/t/n
				{
					iss.ignore(); // discard first slash

					if (iss.peek() != '/') // check if there is a number after first slash -> texture v
					{
						if (!(iss >> indx)) throw "Error parsing face at line: " + lineNumber;
						f.HasTextureVertices = true; // no consitency! should (?) affect following reads
						transformIndex(indx);
						f.TextureIndices.push_back(indx);
						// v/t
						//if (iss.peek() != '/') break; // v/t
					}
					if (iss.peek() == '/') // check for second slash
					{
						iss.ignore(); // discard second slash
						if (!(iss >> indx)) throw "Error parsing face at line: " + lineNumber; // normal v
						f.HasNormalVertices = true;
						transformIndex(indx);
						f.NormalIndices.push_back(indx);
						// v/t/n OR v//n
					}
				}

				while (iss.peek() != EOF) // comtinue reading the rest of face indexes
				{
					if (!(iss >> indx)) break;
					transformIndex(indx);
					f.VertexIndices.push_back(indx);
					iss.ignore(); // first / or space
					if (f.HasTextureVertices)
					{
						if (!(iss >> indx)) break;
						transformIndex(indx);
						f.TextureIndices.push_back(indx);
					}
					if (f.HasNormalVertices)
					{
						iss.ignore(); // second /
						if (!(iss >> indx)) break;
						transformIndex(indx);
						f.NormalIndices.push_back(indx);
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
			else if (keyword == "mtllib")
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
		if (!obj->MaterialLibrary.empty())
		{
			gd->MaterialLibrary = obj->MaterialLibrary;
		}

		for (auto face : obj->Faces)
		{
			for (unsigned int i = 2; i < face.VertexIndices.size(); i++)
			{
				Face3 f3;
				f3.VertexCoords[0] = obj->FileVertices[face.VertexIndices[0]];
				f3.VertexCoords[1] = obj->FileVertices[face.VertexIndices[i - 1]];
				f3.VertexCoords[2] = obj->FileVertices[face.VertexIndices[i]];

				if (face.HasTextureVertices)
				{
					gd->HasTextureVertices = true;
					f3.TextureCoords[0] = obj->FileTextureVertices[face.TextureIndices[0]];
					f3.TextureCoords[1] = obj->FileTextureVertices[face.TextureIndices[i - 1]];
					f3.TextureCoords[2] = obj->FileTextureVertices[face.TextureIndices[i]];
				}
				if (face.HasNormalVertices)
				{
					gd->HasNormalVertices = true;
					f3.NormalCoords[0] = obj->FileNormalVertices[face.NormalIndices[0]];
					f3.NormalCoords[1] = obj->FileNormalVertices[face.NormalIndices[i - 1]];
					f3.NormalCoords[2] = obj->FileNormalVertices[face.NormalIndices[i]];
				}

				gd->TriangleMesh.push_back(f3);
			}
		}
		geoDatavec.push_back(gd);
	}

	return geoDatavec;
}
