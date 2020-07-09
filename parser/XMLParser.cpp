#include "XMLParser.h"
#include <iostream>

Vec3<float> XMLParser::getPosition(TiXmlElement* pElem)
{
	Vec3<float> position;
	position.setX(atof(pElem->Attribute("x")));
	position.setY(atof(pElem->Attribute("y")));
	position.setZ(atof(pElem->Attribute("z")));
	return position;
}

Vec3<float> XMLParser::getColor(TiXmlElement* pElem)
{
	Vec3<float> color;
	color.setX(atof(pElem->Attribute("r")));
	color.setY(atof(pElem->Attribute("g")));
	color.setZ(atof(pElem->Attribute("b")));
	return color;
}

Phong XMLParser::getPhong(TiXmlElement* pElem)
{
	Phong phong;
	phong.ka = atof(pElem->Attribute("ka"));
	phong.kd = atof(pElem->Attribute("kd"));
	phong.ks = atof(pElem->Attribute("ks"));
	phong.exponent = atof(pElem->Attribute("exponent"));
	return phong;
}

Vec3<float> XMLParser::getRotate(TiXmlElement* pElem, const char *axis)
{
	if(!strcmp(axis,"rotateX")){
		return Vec3<float>(atof(pElem->Attribute("theta")), 0, 0);
	}else if(!strcmp(axis,"rotateX")){
		return Vec3<float>(atof(pElem->Attribute("theta")), 0, 0);
	}else if(!strcmp(axis,"rotateX")){
		return Vec3<float>(atof(pElem->Attribute("theta")), 0, 0);
	}
	return Vec3<float>(0, 0, 0);
}

SolidMaterial* XMLParser::getSolidMaterial(TiXmlElement* pElem)
{
	Vec3<float> color;
	Phong phong;
	float reflectance;
	float transmittance;
	float refraction;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "color")){
			color = getColor(pElem);
		}
		if(!strcmp(pElem->Value(), "phong")){
			phong = getPhong(pElem);
		}
		if(!strcmp(pElem->Value(), "reflectance")){
			reflectance = atof(pElem->Attribute("r"));
		}
		if(!strcmp(pElem->Value(), "transmittance")){
			transmittance = atof(pElem->Attribute("t"));
		}
		if(!strcmp(pElem->Value(), "refraction")){
			refraction = atof(pElem->Attribute("iof"));
		}
	}
	return new SolidMaterial(phong, reflectance, transmittance, refraction, color);
}

TexturedMaterial* XMLParser::getTexturedMaterial(TiXmlElement* pElem)
{
	std::string texture;
	Phong phong;
	float reflectance;
	float transmittance;
	float refraction;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "texture")){
			texture = pElem->Attribute("name");
		}
		if(!strcmp(pElem->Value(), "phong")){
			phong = getPhong(pElem);
		}
		if(!strcmp(pElem->Value(), "reflectance")){
			reflectance = atof(pElem->Attribute("r"));
		}
		if(!strcmp(pElem->Value(), "transmittance")){
			transmittance = atof(pElem->Attribute("t"));
		}
		if(!strcmp(pElem->Value(), "refraction")){
			refraction = atof(pElem->Attribute("iof"));
		}
	}
	return new TexturedMaterial(phong, reflectance, transmittance, refraction, texture);
}

void XMLParser::addTransform(TiXmlElement* pElem, Surface &surface)
{
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "translate")){
			surface.addTransform(TRANSLATE, getPosition(pElem));
		}
		if(!strcmp(pElem->Value(), "scale")){
			surface.addTransform(SCALE, getPosition(pElem));
		}
		if(!strcmp(pElem->Value(), "rotateX")){
			surface.addTransform(ROTATE, getRotate(pElem, "rotateX"));
		}
		if(!strcmp(pElem->Value(), "rotateY")){
			surface.addTransform(ROTATE, getRotate(pElem, "rotateY"));
		}
		if(!strcmp(pElem->Value(), "rotateZ")){
			surface.addTransform(ROTATE, getRotate(pElem, "rotateZ"));
		}
	}
}

Camera XMLParser::getCamera(TiXmlElement* pElem)
{
	Camera camera;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "position")){
			camera.setPosition(getPosition(pElem));
		}
		if(!strcmp(pElem->Value(), "lookat")){
			camera.setLookat(getPosition(pElem));
		}
		if(!strcmp(pElem->Value(), "up")){
			camera.setUp(getPosition(pElem));
		}
		if(!strcmp(pElem->Value(), "horizontal_fov")){
			double angle= atof(pElem->Attribute("angle"));
			camera.setHorizontalFov(angle);
		}
		if(!strcmp(pElem->Value(), "resolution")){
			int horizontal= atoi(pElem->Attribute("horizontal"));
			int vertical= atoi(pElem->Attribute("vertical"));
			camera.setResolutionHorizontal(horizontal);
			camera.setResolutionVertical(vertical);
		}
		if(!strcmp(pElem->Value(), "max_bounces")){
			int max_bounces= atoi(pElem->Attribute("n"));
			camera.setMaxBounces(max_bounces);
		}
	}
	return camera;
}

Light* XMLParser::getAmbientLight(TiXmlElement* pElem)
{
	Vec3<float> color;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "color")){
			color = getColor(pElem);
		}
	}
	return new Light(color);
}

Light* XMLParser::getParallelLight(TiXmlElement* pElem)
{
	Vec3<float> color;
	Vec3<float> direction;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "color")){
			color = getColor(pElem);
		}
		if(!strcmp(pElem->Value(), "direction")){
			direction = getPosition(pElem);
		}
	}
	return new ParallelLight(color, direction);
}

Light* XMLParser::getPointLight(TiXmlElement* pElem)
{
	Vec3<float> color;
	Vec3<float> position;
	for(pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "color")){
			color = getColor(pElem);
		}
		if(!strcmp(pElem->Value(), "position")){
			position = getPosition(pElem);
		}
	}
	return new PointLight(color, position);
}

Light* XMLParser::getSpotLight(TiXmlElement* pElem)
{
	Vec3<float> color;
	Vec3<float> position;
	Vec3<float> direction;
	double alpha1;
	double alpha2;
	for( pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "color")){
			color = getColor(pElem);
		}
		if(!strcmp(pElem->Value(), "position")){
			position = getPosition(pElem);
		}
		if(!strcmp(pElem->Value(), "direction")){
			direction = getPosition(pElem);
		}
		if(!strcmp(pElem->Value(), "falloff")){
			alpha1 = atof(pElem->Attribute("alpha1"));
			alpha2 = atof(pElem->Attribute("alpha2"));
		}
	}
	return new SpotLight(color, position, direction, alpha1, alpha2);
}

Sphere* XMLParser::getSphere(TiXmlElement* pElem)
{
	Sphere sphere;
	double radius = atof(pElem->Attribute("radius"));
	sphere.setRadius(radius);
	TiXmlElement* surfaceElem = pElem->FirstChild()->ToElement();
	for( surfaceElem; surfaceElem; surfaceElem = surfaceElem->NextSiblingElement()){

		if(!strcmp(surfaceElem->Value(), "position")){
			sphere.setPosition(getPosition(surfaceElem));
		}
		if(!strcmp(surfaceElem->Value(), "material_solid")){
			TiXmlElement* materialElem = surfaceElem->FirstChild()->ToElement();
			sphere.setMaterial(std::shared_ptr<Material>(getSolidMaterial(materialElem)));
		}
		if(!strcmp(surfaceElem->Value(), "material_textured")){
			TiXmlElement* materialElem = surfaceElem->FirstChild()->ToElement();
			sphere.setMaterial(std::shared_ptr<Material>(getTexturedMaterial(materialElem)));
		}
		if(!strcmp(surfaceElem->Value(), "transform")){
			TiXmlElement* transformElem = surfaceElem->FirstChild()->ToElement();
			addTransform(transformElem, sphere);
		}
	}
	return new Sphere(sphere);
}

Mesh* XMLParser::getMesh(TiXmlElement* pElem)
{
	Mesh mesh;
	std::string name = pElem->Attribute("name");
	mesh.setName(name);
	TiXmlElement* surfaceElem = pElem->FirstChild()->ToElement();
	for( surfaceElem; surfaceElem; surfaceElem = surfaceElem->NextSiblingElement()){
		if(!strcmp(surfaceElem->Value(), "material_solid")){
			TiXmlElement* materialElem = surfaceElem->FirstChild()->ToElement();
			mesh.setMaterial(std::shared_ptr<Material>(getSolidMaterial(materialElem)));
		}
		if(!strcmp(surfaceElem->Value(), "material_textured")){
			TiXmlElement* materialElem = surfaceElem->FirstChild()->ToElement();
			mesh.setMaterial(std::shared_ptr<Material>(getTexturedMaterial(materialElem)));
		}
		if(!strcmp(surfaceElem->Value(), "transform")){
			TiXmlElement* transformElem = surfaceElem->FirstChild()->ToElement();
			addTransform(transformElem, mesh);
		}
	}
	return new Mesh(mesh);
}

void XMLParser::loadLights(TiXmlHandle &hRoot, Scene &scene)
{
	TiXmlElement* pElem = hRoot.FirstChild("lights").FirstChild().Element();
		for( pElem; pElem; pElem = pElem->NextSiblingElement()){
			if(!strcmp(pElem->Value(), "ambient_light")){
				TiXmlElement* lightElem = pElem->FirstChild()->ToElement();
				scene.addLight(std::shared_ptr<Light>(getAmbientLight(pElem)));
			}
			if(!strcmp(pElem->Value(), "parallel_light")){
				TiXmlElement* lightElem = pElem->FirstChild()->ToElement();
				scene.addLight(std::shared_ptr<Light>(getParallelLight(lightElem)));
			}
			if(!strcmp(pElem->Value(), "point_light")){
				TiXmlElement* lightElem = pElem->FirstChild()->ToElement();
				scene.addLight(std::shared_ptr<Light>(getPointLight(pElem)));
			}
			if(!strcmp(pElem->Value(), "spot_light")){
				TiXmlElement* lightElem = pElem->FirstChild()->ToElement();
				scene.addLight(std::shared_ptr<Light>(getSpotLight(pElem)));
			}
		}
}

void XMLParser::loadSurfaces(TiXmlHandle &hRoot, Scene &scene)
{
	TiXmlElement* pElem = hRoot.FirstChild("surfaces").FirstChild().Element();
	Phong phong;
	double reflectance = 0;
	double transmittance = 0;
	double refraction = 0;
	std::string texture;
	for( pElem; pElem; pElem = pElem->NextSiblingElement()){
		if(!strcmp(pElem->Value(), "sphere")){
			scene.addSurface(std::shared_ptr<Surface>(getSphere(pElem)));
		}
		if(!strcmp(pElem->Value(), "mesh")){
			scene.addSurface(std::shared_ptr<Surface>(getMesh(pElem)));
		}
	}
}

void XMLParser::loadCamera(TiXmlHandle &hRoot, Scene &scene)
{
	Camera camera;
	TiXmlElement* pElem = hRoot.FirstChild("camera").FirstChild().Element();
	scene.setCamera(getCamera(pElem));
}

Scene XMLParser::load(const char* sceneFileName)
{
	Scene scene;
	TiXmlDocument doc(sceneFileName);
	doc.LoadFile();
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);
	Vec3<float> color;

	pElem = hDoc.FirstChildElement().Element();
	std::string m_name = pElem->Value();
	hRoot = TiXmlHandle(pElem);
	scene.setOutputFile(pElem->Attribute("output_file"));
	pElem = hRoot.FirstChild("background_color").Element();
	scene.setBackgroudColor(getColor(pElem));

	loadCamera(hRoot, scene);
	loadLights(hRoot, scene);
	loadSurfaces(hRoot, scene);

	return scene;
}