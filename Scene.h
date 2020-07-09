#ifndef SCENE_H
#define SCENE_H

#include "surface/Surface.h"
#include "light/Light.h"
#include "camera/Camera.h"
#include <vector>
#include <string>
#include <memory>
#include "Vec3.h"

class Scene
{
private:
	std::string outputFile;
	std::vector<std::shared_ptr<Surface>> surfaces;
	std::vector<std::shared_ptr<Light>> lights;
	Camera camera;
	Vec3<float> backgroudColor;
public:
	Scene();
	void addSurface(std::shared_ptr<Surface> surface);
	std::vector<std::shared_ptr<Surface>> getSurfaces() const;
	void addLight(std::shared_ptr<Light> light);
	std::vector<std::shared_ptr<Light>> getLights() const;
	void setCamera(Camera camera);
	Camera getCamera();
	void setOutputFile(std::string outputFile);
	std::string getOutputFile();
	void setBackgroudColor(Vec3<float> backgroudColor);
	Vec3<float> getBackgroundColor() const;
};

#endif