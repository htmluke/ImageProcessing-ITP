#include "transform.h"
#include "file.h"

Image rotate90DegreesLeft(Image img)
{	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = (Pixel**) calloc(rotated.height, sizeof(Pixel*));
	
	for(i = 0; i < rotated.height; i++)
	{
		rotated.pixels[i] = (Pixel*) calloc(rotated.width, sizeof(Pixel));
	}

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[j][img.width - i - 1].red;
			rotated.pixels[i][j].green = img.pixels[j][img.width - i - 1].green;
			rotated.pixels[i][j].blue = img.pixels[j][img.width - i - 1].blue;
		}

	}

	return rotated;
}

Image rotate90DegreesRight(Image img)
{	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = (Pixel**) calloc(rotated.height, sizeof(Pixel*));
	
	for(i = 0; i < rotated.height; i++)
	{
		rotated.pixels[i] = (Pixel*) calloc(rotated.width, sizeof(Pixel));
	}

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[img.height - j - 1][i].red;
			rotated.pixels[i][j].green = img.pixels[img.height - j - 1][i].green;
			rotated.pixels[i][j].blue = img.pixels[img.height - j - 1][i].blue;
		}

	}

	return rotated;
}

Image zoomIn(Image img)
{
	int i, j;
	Image zoom;
	
	zoom.height = img.height * 2;
	zoom.width = img.width * 2;
	zoom.maxRGB = img.maxRGB;
		
	zoom.pixels = (Pixel**) calloc(zoom.height,  sizeof(Pixel*));
	for(i = 0; i < zoom.height; i++)
	{
		zoom.pixels[i] = (Pixel*) calloc(zoom.width, sizeof(Pixel));
	}	
		
		for(i = 0; i < zoom.height; i++)
		{
			int aux;
			if(i%2 == 0)
			{
				aux = i/2;
			}
			else
			{
				aux = (i - 1)/2;
			}
			for(j = 0; j < zoom.width; j++)
			{
				if(j%2 ==0)
				{	
					zoom.pixels[i][j].red = img.pixels[aux][j/2].red;
					zoom.pixels[i][j].green = img.pixels[aux][j/2].green;
					zoom.pixels[i][j].blue = img.pixels[aux][j/2].blue;
				}
				else
				{
					zoom.pixels[i][j].red = img.pixels[aux][(j-1)/2].red;
					zoom.pixels[i][j].green = img.pixels[aux][(j-1)/2].green;
					zoom.pixels[i][j].blue = img.pixels[aux][(j-1)/2].blue;
				}
			}
		}
	
	return zoom;
}
Image zoomOut(Image img)
{	
	int i, j;
	Image zoom;
	if(img.height % 2 == 0)
	{
		zoom.height = img.height / 2;	
	}
	else
	{
		zoom.height = (img.height - 1) / 2;	
	}
	if(img.width % 2 == 0)
	{
		zoom.width = img.width / 2;	
	}
	else
	{
		zoom.width = (img.width - 1) / 2;	
	}
	zoom.maxRGB = img.maxRGB;
	printf("Tamanho: %d x %d\n", zoom.height, zoom.width);
	zoom.pixels = (Pixel**) calloc(zoom.height,  sizeof(Pixel*));
	for(i = 0; i < zoom.height; i++)
	{
		zoom.pixels[i] = (Pixel*) calloc(zoom.width, sizeof(Pixel));
	}
	int aux1=0, aux2=0;
	for(i = 0; i < img.height; i+=2)
	{
		for(j = 0; j < img.width; j+=2)
		{
			zoom.pixels[aux1][aux2].red = ((img.pixels[i][j].red + img.pixels[i+1][j].red + img.pixels[i+1][j+1].red + img.pixels[i][j+1].red)/4);
			zoom.pixels[aux1][aux2].green = ((img.pixels[i][j].green + img.pixels[i+1][j].green + img.pixels[i+1][j+1].green + img.pixels[i][j+1].green)/4);
			zoom.pixels[aux1][aux2].blue = ((img.pixels[i][j].blue + img.pixels[i+1][j].blue + img.pixels[i+1][j+1].blue + img.pixels[i][j+1].blue)/4);
			aux2++;
		}
		aux2 = 0;
		aux1++;
	}
	return zoom;	
}
