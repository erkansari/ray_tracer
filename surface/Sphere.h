#ifndef SPHERE_H
#define SPHERE_H

#include "Surface.h"

class Sphere : public Surface
{
private:
	Vec3<float> position;
	double radius;
public:
	Sphere();
	Sphere(Sphere &sphere);
	Sphere(std::shared_ptr<Material> material, std::vector<Transform> transforms, Vec3<float> position);
	virtual bool intersect(const Vec3<float> &origin, const Vec3<float> &direction, float &t0, float &t1);
	void setPosition(Vec3<float> position);
	Vec3<float> getPosition();
	void setRadius(double radius);
	double getRadius();
	Vec3<float> getHitPointNormal(Vec3<float> hit_point);
};

#endif