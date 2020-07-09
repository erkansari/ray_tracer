
#include "PointLight.h"

PointLight::PointLight(Vec3<float> color, Vec3<float> position):
Light(color)
{
	this->position.setX(position.getX());
	this->position.setZ(position.getY());
	this->position.setY(position.getZ());
}

Vec3<float> PointLight::toLightVector(Vec3<float> hit_point)
{
	return this->position - hit_point;
}