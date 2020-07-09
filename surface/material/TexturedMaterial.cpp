#include "TexturedMaterial.h"

TexturedMaterial::TexturedMaterial(Phong phong, double reflectance, double transmittance, double refraction, std::string name):
Material(phong, reflectance, transmittance, refraction)
{
	this->name = name;
	setTexture();
}

std::string TexturedMaterial::getName()
{
	return this->name;
}

Vec3<float> TexturedMaterial::getColor()
{
	float i = (1 - u - v) * vt1.getX() + u * vt2.getX() + v * vt3.getX();
	float j = (1 - u - v) * vt1.getY() + u * vt2.getY() + v * vt3.getY();
	float x = floor(texture.size() * (1 - j));
	float y = floor(texture[0].size() * i);
	return texture[x][y];
}

void TexturedMaterial::setTexture()
{
	PNGParser png_parser;
	png_parser.readPngFile(name, this->texture);
}