#include <iostream>
#include "Ppm.h"
#include "light/Light.h"
#include "light/ParallelLight.h"
#include "light/PointLight.h"
#include "camera/Camera.h"
#include "Scene.h"
#include "parser/XMLParser.h"
#include <string>
#include "Scene.h"
#include "surface/Surface.h"
#include "surface/Sphere.h"
#include <cmath>
#include "surface/material/SolidMaterial.h"
#include <limits>
#include "Vec3.h"
#include <math.h>
#include "parser/PNGParser.h"

Vec3<float> trace(const Vec3<float> &origin, const Vec3<float> &direction, const Scene &scene, int bounce)
{
	Vec3<float> color;
	std::shared_ptr<Surface> surface = NULL;
	float tnear = std::numeric_limits<float>::max();
	float t0, t1;
	int surface_id;

	for(int i = 0; i < scene.getSurfaces().size(); i++){
		if(scene.getSurfaces()[i]->intersect(origin, direction, t0, t1)){
			if(t0 < tnear){
				tnear = t0;
				surface = scene.getSurfaces()[i];
				surface_id = i;
			}
		}
	}

	if(surface == NULL)return scene.getBackgroundColor();

	Vec3<float> hit_point = origin + direction * tnear;

	Vec3<float> hit_point_normal = surface->getHitPointNormal(hit_point);

	color = surface->getMaterial()->getColor() *
						surface->getMaterial()->getPhong().ka;

	if(scene.getLights().size() == 1) return color;

	for(int light_count = 0; light_count < scene.getLights().size(); light_count++){
		bool shadow = false;
		Vec3<float> to_light = scene.getLights()[light_count]->toLightVector(hit_point);
		to_light.normalize();
		
		float dummy_t0, dummy_t1;
		for(int i = 0; i < scene.getSurfaces().size(); i++){
			if(scene.getSurfaces()[i]->intersect(hit_point, to_light, dummy_t0, dummy_t1) && surface_id != i){
				shadow = true;
				break;
			}
		}
		if(shadow) continue;
		if(hit_point_normal.dot(-to_light) < 0){
			color = color + surface->getMaterial()->getColor() * surface->getMaterial()->getPhong().ks * (hit_point_normal.dot(to_light));
		}

		Vec3<float> reflected = hit_point_normal * 2 * hit_point_normal.dot(-to_light) + to_light;
		reflected.normalize();

		Vec3<float> eye = -direction;
		eye.normalize();

		if(eye.dot(reflected) < 0){
			color = color + surface->getMaterial()->getColor() * 
					pow(-eye.dot(reflected), surface->getMaterial()->getPhong().exponent) * surface->getMaterial()->getPhong().ks;
		}
		if(color.getX() > 1) color.setX(1);
		if(color.getY() > 1) color.setY(1);
		if(color.getZ() > 1) color.setZ(1);
	}
	return color;
}

void render(Scene &scene)
{
	int width = scene.getCamera().getResolutionHorizontal();
	int height = scene.getCamera().getResolutionVertical();

	Vec3<float> origin = scene.getCamera().getPosition();
	Vec3<float> look_at = scene.getCamera().getLookat();
	Vec3<float> up = scene.getCamera().getUp();
	Vec3<float> direction;

	float fovx = scene.getCamera().getHorizontalFov() * M_PI / 180;
	float scalex =  tan(fovx);
	float scaley = tan(height / width * fovx);

	std::vector<std::vector<Vec3<float>>> frame_buffer(height, std::vector<Vec3<float>>(width));
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			float x = ((2 * (j + 0.5) - width) / width) * scalex;
			float y = (1 - 2 * (i + 0.5) / height) * scaley;

			direction.setX(x);
			direction.setY(y);
			direction.setZ(-1);
			direction.normalize();
			frame_buffer[i][j] = trace(origin, direction, scene, scene.getCamera().getMaxBounces());
		}
	}

	//Ppm image;
	//image.writeFile(width, height, scene.getOutputFile(), frame_buffer);
	PNGParser p;
	p.writePngFile(scene.getOutputFile(), frame_buffer);
}

int main(int argc, char *argv[])
{
	XMLParser parser;
	Scene scene = parser.load(argv[1]);
	std::vector<std::shared_ptr<Surface>> vect;
	vect.push_back(std::shared_ptr<Surface> (new Sphere()));
	render(scene);
}

