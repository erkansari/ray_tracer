#include "Scene.h"

Scene::Scene()
{

}

void Scene::addSurface(std::shared_ptr<Surface> surface)
{
	this->surfaces.push_back(surface);
}

std::vector<std::shared_ptr<Surface>> Scene::getSurfaces() const
{
	return this->surfaces;
}

void Scene::addLight(std::shared_ptr<Light> light)
{
	this->lights.push_back(light);
}

std::vector<std::shared_ptr<Light>> Scene::getLights() const
{
	return this->lights;
}

void Scene::setCamera(Camera camera)
{
	this->camera = camera;
}

Camera Scene::getCamera()
{
	return this->camera;
}

void Scene::setOutputFile(std::string outputFile)
{
	this->outputFile = outputFile;
}

std::string Scene::getOutputFile()
{
	return this->outputFile;
}

void Scene::setBackgroudColor(Vec3<float> backgroudColor)
{
	this->backgroudColor = backgroudColor;
}

Vec3<float> Scene::getBackgroundColor() const
{
	return this->backgroudColor;
}