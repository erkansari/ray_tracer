#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "PointLight.h"
#include "ParallelLight.h"

class SpotLight : public PointLight
{
private:
	double alpha1;
	double alpha2;
	Vec3<float> direction;
public:
	SpotLight(Vec3<float> color, Vec3<float> position, Vec3<float> direction, double alpha1, double alpha2);
	Vec3<float> toLightVector(Vec3<float> hit_point);
};

#endif