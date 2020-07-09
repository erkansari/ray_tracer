#ifndef SOLID_MATERIAL_H
#define SOLID_MATERIAL_H

#include "Material.h"
#include "../../Vec3.h"

class SolidMaterial : public Material
{
private:
	Vec3<float> color;
public:
	SolidMaterial(Phong phong, double reflectance, double transmittance, double refraction, Vec3<float> color);
	Vec3<float> getColor();
};

#endif