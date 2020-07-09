#ifndef PARALLEL_LIGHT_H
#define PARALLEL_LIGHT_H

#include "Light.h"

class ParallelLight : public Light
{
private:
	Vec3<float> direction;
public:
	ParallelLight(Vec3<float> color, Vec3<float> direction);
	Vec3<float> getDirection();
	Vec3<float> toLightVector(Vec3<float> hit_point);
};

#endif