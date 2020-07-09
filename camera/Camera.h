#ifndef CAMERA_H
#define CAMERA_H

#include "../Vec3.h"

class Camera
{
private:
	Vec3<float> position;
	Vec3<float> lookat;
	Vec3<float> up;
	double horizontal_fov;
	int resolution_horizontal;
	int resolution_vertical;
	int max_bounces;
public:
	Camera(){};
	Camera(Vec3<float> position, Vec3<float> lookat, Vec3<float> up, double horizontal_fov,
			 int resolution_horizontal, int resolution_vertical, int max_bounces);
	void setPosition(Vec3<float> position);
	Vec3<float> getPosition();
	void setLookat(Vec3<float> lookat);
	Vec3<float> getLookat();
	void setUp(Vec3<float> up);
	Vec3<float> getUp();
	void setHorizontalFov(double horizontal_fov);
	double getHorizontalFov();
	void setResolutionHorizontal(int resolution_horizontal);
	int getResolutionHorizontal();
	void setResolutionVertical(int resolution_vertical);
	int getResolutionVertical();
	void setMaxBounces(int max_bounces);
	int getMaxBounces();
};

#endif
