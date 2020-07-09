#ifndef LIGHT_H
#define LIGHT_H

#include "../Vec3.h"

class Light
{
private:
	Vec3<float> color;
public:
	Light(Vec3<float> color);
	virtual ~Light() = default;
	virtual Vec3<float> toLightVector(Vec3<float> hit_point);
};

#endif
