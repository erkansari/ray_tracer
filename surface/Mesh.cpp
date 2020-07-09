#include "Mesh.h"

Mesh::Mesh()
{
	
}

Mesh::Mesh(std::shared_ptr<Material> material, std::vector<Transform> transforms, std::vector<Vec3<float>> vertices):
Surface(material, transforms)
{
	this->vertices = vertices;
}

bool Mesh::intersect(const Vec3<float> &origin, const Vec3<float> &direction, float &t0, float &t1)
{
	int face_count = fragments.size() / 3;
	for(int i = 0; i < face_count; i++){
		int normal_index = fragments[i * 3].getZ() - 1;
		Vec3<float> normal = normals[normal_index];

		Vec3<float> v0 = vertices[fragments[i * 3].getX() - 1];
		Vec3<float> v1 = vertices[fragments[i * 3 + 1].getX() - 1];
		Vec3<float> v2 = vertices[fragments[i * 3 + 2].getX() - 1];

		Vec3<float> v0v1 = v1 - v0;
		Vec3<float> v0v2 = v2 - v0;
		Vec3<float> pvec = direction.cross(v0v2);

		float determinant = pvec.dot(v0v1);
		float denom = normal.dot(normal);

		if(determinant <= 0) continue;

		Vec3<float> tvec = origin - v0;
		float u = pvec.dot(tvec) / determinant;
		if(u < 0 || u > 1) continue;

		Vec3<float> qvec = tvec.cross(v0v1);
		float v = qvec.dot(direction) / determinant;
		if(v < 0 || v + u > 1) continue;

		t0 = qvec.dot(v0v2) / determinant;

		if(t0 > 0){
			this->normal = normal;
			u /= denom;
			v /= denom;
			this->material->setU(u);
			this->material->setV(v);
			this->material->setVt(vertex_texture[fragments[i * 3].getY() - 1],
								 vertex_texture[fragments[i * 3 + 1].getY() - 1],
								 vertex_texture[fragments[i * 3 + 2].getY() - 1]);
			return true;
		}
	}
	return false;
}

void Mesh::setName(std::string name)
{
	this->name = name;
	OBJParser mesh;
	mesh.load(name, vertices, normals, fragments, vertex_texture);
}

std::vector<Vec3<float>> Mesh::getVertices()
{
	return this->vertices;
}

std::string Mesh::getName()
{
	return this->name;
}

Vec3<float> Mesh::getHitPointNormal(Vec3<float> hit_point)
{
	return this->normal;
}
