#include "Transform.h"

Transform::Transform(TransformType transform_type, Vec3<float> axis)
{
	this->transform_type = transform_type;
	this->axis = axis;
}