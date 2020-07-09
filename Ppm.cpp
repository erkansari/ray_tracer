#include "Ppm.h"

Ppm::Ppm(int width, int height, std::string file_name)
{
	this->width = width;
	this->height = height;
	this->file_name = file_name;
	std::vector<Vec3<int>> image_data(width * height);
	this->image_data = image_data;
}

Ppm::Ppm(int width, int height, std::string file_name, std::vector<Vec3<int>> image_data)
{
	this->width = width;
	this->height = height;
	this->image_data = image_data;
	this->file_name = file_name;
}

void Ppm::setImageData(std::vector<Vec3<int>> image_data)
{
	this->image_data = image_data;
}

void Ppm::writeFile()
{
	std::ofstream image(this->file_name);
	image << "P3" << std::endl;
	image << this->width << " " << this->height << std::endl;
	image << "255" << std::endl;
	for(Vec3<int> rgb: this->image_data){
		image << rgb.getX() << " " << rgb.getY() << " " << rgb.getZ() << std::endl;
	}
}

void Ppm::writeFile(int width, int height, std::string file_name, std::vector<std::vector<Vec3<float>>> image_data)
{
	std::ofstream image(file_name);
	image << "P3" << std::endl;
	image << width << " " << height << std::endl;
	image << "255" << std::endl;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			image << (int) (image_data[i][j].getX() * 255) << " " << (int) (image_data[i][j].getY() * 255) << " " << (int) (image_data[i][j].getZ() * 255) << std::endl;
		}
	}
}

void Ppm::writeFile(std::string file_name, std::vector<std::vector<Vec3<float>>> image_data)
{
	int height = image_data.size();
	int width = image_data[0].size();
	std::ofstream image(file_name);
	image << "P3" << std::endl;
	image << width << " " << height << std::endl;
	image << "255" << std::endl;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			image << (int) image_data[i][j].getX() << " " << (int) image_data[i][j].getY() << " " << (int) image_data[i][j].getZ() << std::endl;
		}
	}
}