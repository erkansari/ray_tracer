make:
	g++  -o ray_tracer main.cpp \
			 3rdParty/libpng/png.c \
			 3rdParty/libpng/pngerror.c \
			 3rdParty/libpng/pngget.c \
			 3rdParty/libpng/pngmem.c \
			 3rdParty/libpng/pngread.c \
			 3rdParty/libpng/pngpread.c \
			 3rdParty/libpng/pngrio.c \
			 3rdParty/libpng/pngrtran.c \
			 3rdParty/libpng/pngrutil.c \
			 3rdParty/libpng/pngset.c \
			 3rdParty/libpng/pngtrans.c \
			 3rdParty/libpng/pngwio.c \
			 3rdParty/libpng/pngwrite.c \
			 3rdParty/libpng/pngwtran.c \
			 3rdParty/libpng/pngwutil.c \
			 Ppm.cpp \
			 Scene.cpp \
	  		 camera/Camera.cpp \
			 3rdParty/tinyxml_2_6_2/tinyxml/tinyxml.cpp \
			 3rdParty/tinyxml_2_6_2/tinyxml/tinyxmlparser.cpp \
			 3rdParty/tinyxml_2_6_2/tinyxml/tinyxmlerror.cpp \
			 3rdParty/tinyxml_2_6_2/tinyxml/tinystr.cpp \
	  		 light/Light.cpp \
	  		 light/ParallelLight.cpp \
	  		 light/PointLight.cpp \
	  		 light/SpotLight.cpp \
			 parser/OBJParser.cpp \
			 parser/PNGParser.cpp \
			 parser/XMLParser.cpp \
	  		 surface/Surface.cpp \
	  		 surface/material/Material.cpp \
	  		 surface/material/SolidMaterial.cpp \
	  		 surface/material/TexturedMaterial.cpp \
	  		 surface/Sphere.cpp surface/Mesh.cpp \
	  		 surface/transform/Transform.cpp \
	  		 -lz
