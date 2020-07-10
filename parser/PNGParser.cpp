#include "PNGParser.h"

void PNGParser::readPngFile(std::string file_name, std::vector<std::vector<Vec3<float>>> &image)
{
	file_name = "scenes/scenes/" + file_name;
	FILE *file = fopen(file_name.c_str(), "rb");

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) abort();

	png_infop info = png_create_info_struct(png);
	if(!info) abort();

	if(setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, file);

	png_read_info(png, info);

	int width = png_get_image_width(png, info);
	int height = png_get_image_height(png, info);

	png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
	png_read_update_info(png, info);
	image = std::vector<std::vector<Vec3<float>>>(height, std::vector<Vec3<float>>(width));

	png_bytep *row = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for(int i = 0; i < height; i++){
		row[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	png_read_image(png, row);

	for(int i = 0; i < height; i++){
		png_bytep temp = row[i];
		for(int j = 0; j < width; j++){
			png_bytep pixel = &(temp[j * 4]);
			image[i][j].setX(((float)pixel[0]) / 255);
			image[i][j].setY(((float)pixel[1]) / 255);
			image[i][j].setZ(((float)pixel[2]) / 255);
		}
		free(row[i]);
	}
	free(row);
	fclose(file);
	png_destroy_read_struct(&png, &info, NULL);
}

void PNGParser::writePngFile(std::string file_name, std::vector<std::vector<Vec3<float>>> &image)
{
	FILE *file = fopen(file_name.c_str(), "wb");
	
	int height = image.size();
	int width = image[0].size();

	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png) abort();

	png_infop info = png_create_info_struct(png);
	if (!info) abort();

	if (setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, file);

	if (setjmp(png_jmpbuf(png))) abort();

	png_set_IHDR(png, info, width, height,
					 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
					 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_bytep *row = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for(int i = 0; i < height; i++){
		row[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	for(int i = 0; i < height; i++){
		png_bytep temp = row[i];
		for(int j = 0; j < width; j++){
			png_bytep pixel = &(temp[j * 4]);
			pixel[0] = (int) (image[i][j].getX() * 255);
			pixel[1] = (int) (image[i][j].getY() * 255);
			pixel[2] = (int) (image[i][j].getZ() * 255);
			pixel[3] = 255;
		}
	}

	png_write_info(png, info);
	if(setjmp(png_jmpbuf(png))) abort();
	png_write_image(png, row);
	if(setjmp(png_jmpbuf(png))) abort();
	png_write_end(png, NULL);

	for(int i = 0; i < height; i++){
		free(row[i]);
	}
	free(row);

	fclose(file);
}