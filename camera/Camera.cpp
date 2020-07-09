#include "Camera.h"

Camera::Camera(Vec3<float> position, Vec3<float> lookat, Vec3<float> up, double horizontal_fov,
			 int resolution_horizontal, int resolution_vertical, int max_bounces)
{
	this->position.setX(position.getX());
	this->position.setY(position.getY());
	this->position.setZ(position.getZ());

	this->lookat.setX(lookat.getX());
	this->lookat.setY(lookat.getY());
	this->lookat.setZ(lookat.getZ());

	this->up.setX(up.getX());
	this->up.setY(up.getY());
	this->up.setZ(up.getZ());

	this->horizontal_fov = horizontal_fov;
	this->resolution_horizontal = resolution_horizontal;
	this->resolution_vertical = resolution_vertical;
	this->max_bounces = max_bounces;
}

void Camera::setPosition(Vec3<float> position)
{
	this->position = position; 
}

Vec3<float> Camera::getPosition()
{
	return this->position;
}

void Camera::setLookat(Vec3<float> lookat)
{
	this->lookat = lookat;
}

Vec3<float> Camera::getLookat()
{
	return this->lookat;
}

void Camera::setUp(Vec3<float> up)
{
	this->up = up;
}

Vec3<float> Camera::getUp()
{
	return this->up;
}

void Camera::setHorizontalFov(double horizontal_fov)
{
	this->horizontal_fov = horizontal_fov;
}

double Camera::getHorizontalFov()
{
	return horizontal_fov;
}

void Camera::setResolutionHorizontal(int resolution_horizontal)
{
	this->resolution_horizontal = resolution_horizontal;
}

int Camera::getResolutionHorizontal()
{
	return resolution_horizontal;
}

void Camera::setResolutionVertical(int resolution_vertical)
{
	this->resolution_vertical = resolution_vertical;
}

int Camera::getResolutionVertical()
{
	return this->resolution_vertical;
}

void Camera::setMaxBounces(int max_bounces)
{
	this->max_bounces = max_bounces;
}

int Camera::getMaxBounces()
{
	return this->max_bounces;
}