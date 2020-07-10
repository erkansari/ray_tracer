#ifndef PNG_PARSER_H
#define PNG_PARSER_H

#include <vector>
#include <string>
#include "../3rdParty/libpng/png.h"
#include "../Vec3.h"
#include <iostream>

class PNGParser
{
public:
	void readPngFile(std::string filename, std::vector<std::vector<Vec3<float>>> &image);
	void writePngFile(std::string file_name, std::vector<std::vector<Vec3<float>>> &image);
};

#endif