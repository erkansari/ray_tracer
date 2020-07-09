#ifndef PPM_H
#define PPM_H

#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include "Vec3.h"

class Ppm
{
private:
	std::string file_name;
	int width;
	int height;
	std::vector<Vec3<int>> image_data;
public:
	Ppm(){};
	Ppm(int width, int height, std::string file_name);
	Ppm(int width, int height, std::string file_name, std::vector<Vec3<int>> image_data);
	void setImageData(std::vector<Vec3<int>> image_data);
	void writeFile();
	void writeFile(int width, int height, std::string file_name, std::vector<std::vector<Vec3<float>>> image_data);
	void writeFile(std::string file_name, std::vector<std::vector<Vec3<float>>> image_data);
};

#endif
