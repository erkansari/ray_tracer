#ifndef TEXTURED_MATERIAL_H
#define TEXTURED_MATERIAL_H

#include "Material.h"
#include <string>
#include <vector>
#include <iostream>
#include "../../Vec3.h"
#include "../../parser/PNGParser.h"
#include "../../Ppm.h"

class TexturedMaterial : public Material
{
private:
	std::string name;
	std::vector<std::vector<Vec3<float>>> texture;
	void setTexture();
public:
	TexturedMaterial(Phong phong, double reflectance, double transmittance, double refraction, std::string name);
	std::string getName();
	Vec3<float> getColor();
};

#endif