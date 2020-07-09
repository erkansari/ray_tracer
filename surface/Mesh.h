#ifndef MESH_H
#define MESH_H

#include "Surface.h"
#include <vector>
#include <string>
#include "../parser/OBJParser.h"

class Mesh : public Surface
{
private:
	std::vector<Vec3<float>> vertices;
	std::vector<Vec3<float>> normals;
	std::vector<Vec3<float>> fragments;
	std::vector<Vec3<float>> vertex_texture;
	Vec3<float> normal;
	std::string name;
public:
	Mesh();
	Mesh(std::shared_ptr<Material> material, std::vector<Transform> transforms, std::vector<Vec3<float>> vertices);
	virtual bool intersect(const Vec3<float> &origin, const Vec3<float> &direction, float &t0, float &t1);
	std::vector<Vec3<float>> getVertices();
	void setName(std::string name);
	std::string getName();
	Vec3<float> getHitPointNormal(Vec3<float> hit_point);
};

#endif
