#ifndef MATERIAL_H
#define MATERIAL_H

#include "../../Vec3.h"

struct Phong{
	double ka;
	double kd;
	double ks;
	double exponent;
};

class Material
{
private:
	Phong phong;
	double reflectance;
	double transmittance;
	double refraction;
protected:
	float u;
	float v;
	Vec3<float> vt1;
	Vec3<float> vt2;
	Vec3<float> vt3;
public:
	Material(){};
	Material(Phong phong, double reflectance, double transmittance, double refraction);
	virtual ~Material() = default;
	Phong getPhong();
	double getReflectance();
	double getTransmittance();
	double getRefraction();
	void setU(float u);
	void setV(float v);
	void setVt(Vec3<float> vt1, Vec3<float> vt2, Vec3<float> vt3);
	virtual Vec3<float> getColor() = 0;
};

#endif