
#include "ParallelLight.h"

ParallelLight::ParallelLight(Vec3<float> color, Vec3<float> direction):
Light(color)
{
	this->direction.setX(direction.getX());
	this->direction.setY(direction.getY());
	this->direction.setZ(direction.getZ());
}

Vec3<float> ParallelLight::getDirection()
{
	return this->direction;
}

Vec3<float> ParallelLight::toLightVector(Vec3<float> hit_point)
{
	return -this->direction;
}