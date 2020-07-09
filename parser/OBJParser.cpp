#include "OBJParser.h"

void OBJParser::load(std::string file_name, std::vector<Vec3<float>> &vertices, std::vector<Vec3<float>> &normals,
					 std::vector<Vec3<float>> &fragments, std::vector<Vec3<float>> &vertex_texture)
{
	std::string line;
	std::string delimiter = " ";
	std::string path = "scenes/scenes/" + file_name;
	std::ifstream obj_file(path);
	if(!obj_file.is_open()){
		std::cout << "Unable to open file: " << path << std::endl;
	}

	while(getline(obj_file, line)){
		std::string token = line.substr(0, line.find(delimiter));

		if(!token.compare("v")){
			size_t pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			split(line, delimiter, vertices);
		}

		if(!token.compare("vn")){
			size_t pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			split(line, delimiter, normals);
		}

		if(!token.compare("f")){
			std::string del = "/";
			size_t pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			split(line.substr(0, line.find(delimiter)), del, fragments);
			pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			split(line.substr(0, line.find(delimiter)), del, fragments);
			pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			split(line.substr(0, line.find(delimiter)), del, fragments);
		}

		if(!token.compare("vt")){
			size_t pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			float x = atof(line.substr(0, line.find(delimiter)).c_str());
			pos = line.find(delimiter);
			line.erase(0, pos + delimiter.length());
			float y = atof(line.substr(0, line.find(delimiter)).c_str());
			vertex_texture.push_back(Vec3<float>(x, y, 0));
		}
	}
}

void OBJParser::split(std::string line, std::string delimiter, std::vector<Vec3<float>> &storage)
{
	size_t pos;
	float x = atof(line.substr(0, line.find(delimiter)).c_str());
	pos = line.find(delimiter);
	line.erase(0, pos + delimiter.length());
	float y = atof(line.substr(0, line.find(delimiter)).c_str());
	pos = line.find(delimiter);
	line.erase(0, pos + delimiter.length());
	float z = atof(line.substr(0, line.find(delimiter)).c_str());
	storage.push_back(Vec3<float>(x, y, z));
}