#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../Vec3.h"

class OBJParser
{
public:
	void load(std::string file_name, std::vector<Vec3<float>> &vertices, std::vector<Vec3<float>> &normals, std::vector<Vec3<float>> &fragments, std::vector<Vec3<float>> &vertex_texture);
	void split(std::string line, std::string delimiter, std::vector<Vec3<float>> &storage);
};

#endif