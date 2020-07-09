#ifndef SURFACE_H
#define SURFACE_H

#include <cmath>
#include <vector>
#include <memory>

#include "material/Material.h"
#include "transform/Transform.h"
#include "../Vec3.h"

class Surface
{
protected:
	std::shared_ptr<Material> material;
	std::vector<Transform> transforms;
public:
	Surface();
	Surface(std::shared_ptr<Material> material, std::vector<Transform> transforms);
	virtual ~Surface() = default;
	virtual bool intersect(const Vec3<float> &origin, const Vec3<float> &direction, float &t0, float &t1) = 0;
	bool solveQuadratic(const float &a, const float &b, const float &c, float &t0, float &t1);
	void addTransform(TransformType transformType, Vec3<float> coordinates);
	void setMaterial(std::shared_ptr<Material> material);
	std::shared_ptr<Material> getMaterial();
	std::vector<Transform> getTransform();
	virtual Vec3<float> getHitPointNormal(Vec3<float> hit_point) = 0;
};

#endif
