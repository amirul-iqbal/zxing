#include "CameraImage.h"


CameraImage::CameraImage() : LuminanceSource()
{
}

CameraImage::CameraImage(CameraImage& otherInstance) : LuminanceSource()
{
	 image = otherInstance.getImage();
}

CameraImage::~CameraImage()
{
}

int CameraImage::getWidth()
{
     return image->SizeInPixels().iWidth;
}

int CameraImage::getHeight()
{
     return image->SizeInPixels().iHeight;
}

unsigned char CameraImage::getPixel(int x, int y)
{
	TPoint pixelPosition(x,y);
	TRgb color;
    image->GetPixel(color, pixelPosition); 
    return ((color.Red() + color.Green() + color.Blue()) / 3);
}

void CameraImage::setImage(CFbsBitmap* newImage)
{
    image = newImage;
}

CFbsBitmap* CameraImage::getImage()
{
	return image;
}


