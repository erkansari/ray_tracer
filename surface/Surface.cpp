#include "Surface.h"

Surface::Surface()
{

}

Surface::Surface(std::shared_ptr<Material> material, std::vector<Transform> transforms)
{
	this->material = material;
	this->transforms = transforms;
}

bool Surface::solveQuadratic(const float &a, const float &b, const float &c, float &t0, float &t1)
{
	float discriminant = b * b - 4 * a * c;
	if(discriminant < 0)return false;
	if(discriminant == 0){
		t0 = -b / 2;
		t1 = -b / 2;
	}else{
		t0 = (-b + sqrt(discriminant)) / 2;
		t1 = (-b - sqrt(discriminant)) / 2;
	}
	if(t0 > t1) std::swap(t0, t1);
	if (t0 < 0) {
		t0 = t1;
		if (t0 < 0) return false;
	}
	return true;
}

void Surface::addTransform(TransformType transformType, Vec3<float> coordinates)
{
	this->transforms.push_back(Transform(transformType, coordinates));
}

void Surface::setMaterial(std::shared_ptr<Material> material)
{
	this->material = material;
}

std::shared_ptr<Material> Surface::getMaterial()
{
	return this->material;
}

std::vector<Transform> Surface::getTransform()
{
	return this->transforms;
}
