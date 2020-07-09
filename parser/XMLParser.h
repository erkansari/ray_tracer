#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "../3rdParty/tinyxml_2_6_2/tinyxml/tinyxml.h"
#include "../Scene.h"
#include "../Vec3.h"
#include "../camera/Camera.h"
#include "../light/Light.h"
#include "../light/ParallelLight.h"
#include "../light/PointLight.h"
#include "../light/SpotLight.h"
#include "../surface/material/Material.h"
#include "../surface/material/TexturedMaterial.h"
#include "../surface/material/SolidMaterial.h"
#include <string>
#include "../surface/Sphere.h"
#include "../surface/Mesh.h"

class XMLParser
{
private:
	Vec3<float> getPosition(TiXmlElement* pElem);
	Vec3<float> getColor(TiXmlElement* pElem);
	Phong getPhong(TiXmlElement* pElem);
	Vec3<float> getRotate(TiXmlElement* pElem, const char *axis);
	SolidMaterial* getSolidMaterial(TiXmlElement* pElem);
	TexturedMaterial* getTexturedMaterial(TiXmlElement* pElem);
	void addTransform(TiXmlElement* pElem, Surface &surface);
	Camera getCamera(TiXmlElement* pElem);
	Light* getAmbientLight(TiXmlElement* pElem);
	Light* getParallelLight(TiXmlElement* pElem);
	Light* getPointLight(TiXmlElement* pElem);
	Light* getSpotLight(TiXmlElement* pElem);
	Sphere* getSphere(TiXmlElement* pElem);
	Mesh* getMesh(TiXmlElement* pElem);
	void loadLights(TiXmlHandle &hRoot, Scene &scene);
	void loadSurfaces(TiXmlHandle &hRoot, Scene &scene);
	void loadCamera(TiXmlHandle &hRoot, Scene &scene);
public:
	Scene load(const char* sceneFileName);
};

#endif
