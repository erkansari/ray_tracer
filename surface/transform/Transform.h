#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../../Vec3.h"

enum TransformType {TRANSLATE, SCALE, ROTATE};

class Transform
{
private:
	TransformType transform_type;
	Vec3<float> axis;
public:
	Transform(TransformType transform_type, Vec3<float> axis);
};

#endif
