#include "Material.h"

Material::Material(Phong phong, double reflectance, double transmittance, double refraction)
{
	this->phong = phong;
	this->reflectance = reflectance;
	this->transmittance = transmittance;
	this->refraction = refraction;
}

Phong Material::getPhong()
{
	return this->phong;
}

double Material::getReflectance()
{
	return this->reflectance;
}

double Material::getTransmittance()
{
	return this->transmittance;
}

double Material::getRefraction()
{
	return this->refraction;
}

void Material::setU(float u)
{
	this->u = u;
}

void Material::setV(float v)
{
	this->v = v;
}

void Material::setVt(Vec3<float> vt1, Vec3<float> vt2, Vec3<float> vt3)
{
	this->vt1 = vt1;
	this->vt2 = vt2;
	this->vt3 = vt3;
}