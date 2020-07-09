#include "Light.h"

Light::Light(Vec3<float> color)
{
	this->color.setX(color.getX());
	this->color.setY(color.getY());
	this->color.setZ(color.getZ());
}

Vec3<float> Light::toLightVector(Vec3<float> hit_point)
{
	return Vec3<float>(0,0,0);
}