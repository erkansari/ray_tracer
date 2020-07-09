#include "Sphere.h"
#include <iostream>
Sphere::Sphere()
{

}

Sphere::Sphere(Sphere &sphere)
{
	this->radius = sphere.radius;
	this->material = sphere.material;
	this->transforms = sphere.transforms;
	this->position = sphere.position;
}

Sphere::Sphere(std::shared_ptr<Material> material, std::vector<Transform> transforms, Vec3<float> position):
Surface(material, transforms)
{
	this->position = position;
}

bool Sphere::intersect(const Vec3<float> &origin, const Vec3<float> &direction, float &t0, float &t1)
{
	Vec3<float> distance;
	distance.setX(origin.getX() - this->position.getX());
	distance.setY(origin.getY() - this->position.getY());
	distance.setZ(origin.getZ() - this->position.getZ());

	float a = direction.dot(direction);
	float b = 2 * direction.dot(distance);
	float c = distance.dot(distance) - radius * radius;
	if (!solveQuadratic(a, b, c, t0, t1)) return false;
	return true;
}

void Sphere::setPosition(Vec3<float> position)
{
	this->position = position;
}

Vec3<float> Sphere::getPosition()
{
	return this->position;
}

void Sphere::setRadius(double radius)
{
	this->radius = radius;
}

double Sphere::getRadius()
{
	return this->radius;
}

Vec3<float> Sphere::getHitPointNormal(Vec3<float> hit_point)
{
	Vec3<float> hit_point_normal =  hit_point - this->position;
	hit_point_normal.normalize();
	return hit_point_normal;
}