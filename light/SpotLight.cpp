
#include "SpotLight.h"

SpotLight::SpotLight(Vec3<float> color, Vec3<float> position, Vec3<float> direction, double alpha1, double alpha2):
PointLight(color, position)
{
	this->alpha1 = alpha1;
	this->alpha2 = alpha2;
}

Vec3<float> SpotLight::toLightVector(Vec3<float> hit_point)
{
	return this->direction - hit_point;
}