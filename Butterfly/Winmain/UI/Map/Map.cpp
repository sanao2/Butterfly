#include "Map.h"

Map::Object::Object(HDC drawDC, int width, int height) 
	: memDC(drawDC), clientSize{width,height}, 
	  ObjectPos{0,0}, ObjectScale{0,0}
{
	imageResource = new ImageResource(); 
	imageRenderer = new GdiPlusImageRenderer();

	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	Gdiplus::Graphics* g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(memDC);
}

Map::Object::~Object()
{
	delete image; 
	delete graphics; 
	delete imageRenderer; 
	delete imageResource; 
	DeleteDC(memDC);
	Gdiplus::GdiplusShutdown(GdiPlusToken);
}

Gdiplus::Image* Map::Object::LoadImages(HINSTANCE hInstance, int SpriteID)
{
	imageResource->LoadFromResource(hInstance, SpriteID, SPRITE_TYPE);

	image = imageResource->GetBitmap(); 

	if (image == nullptr)
	{
		cerr << "Failed to load image resource." << endl;
		return nullptr;
	}
	return image; 
}



void Map::Object::Render(HDC drawDC,Gdiplus::Graphics* graphics, Gdiplus::Image* image, int width, int height, int x, int y)
{
	int Objwidth = image->GetWidth(); 
	int Objheight = image->GetHeight(); 

	Gdiplus::Rect destRect = { x,y,Objwidth,Objheight };
	imageRenderer->Render(*graphics, image, width, height, x, y);
}

