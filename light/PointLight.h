#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.h"

class PointLight : public Light
{
private:
	Vec3<float> position;
public:
	PointLight(Vec3<float> color, Vec3<float> position);
	virtual Vec3<float> toLightVector(Vec3<float> hit_point);
};

#endif