#include "SolidMaterial.h"

SolidMaterial::SolidMaterial(Phong phong, double reflectance, double transmittance, double refraction, Vec3<float> color):
Material(phong, reflectance, transmittance, refraction)
{
	this->color = color;
}

Vec3<float>  SolidMaterial::getColor()
{
	return this->color;
}