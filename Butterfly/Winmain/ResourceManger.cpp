#include "ResourceManger.h"

ResourceManger::ResourceManger(HDC drawDC,  HINSTANCE hInstance, int width, int height) 
																	: hInst(hInstance)
{
	imageResource = new ImageResource();
		
	Gdiplus::GdiplusStartupInput gsi; 
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr); 
	graphics = new Gdiplus::Graphics(hWnd); 

}

ResourceManger::~ResourceManger()
{	
	DeleteObject(bitmap); 
	delete hInst;
	delete imageResource;
	delete imageRenderer; 
	delete graphics;
	Gdiplus::GdiplusShutdown(GdiPlusToken);

}

void ResourceManger::Initialize()
{
	
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); 
	bitmap = imageResource->GetBitmap(); 

	if (bitmap == nullptr)
	{
		cerr << "Failed to load image resource." << endl;
		return;
	}
}

void ResourceManger::RenderImage(Gdiplus::Graphics& graphics, int x, int y)
{
	if (bitmap == nullptr)
	{
		cerr << "Bitmap is null." << endl;
		return;
	} 
	imageRenderer->Render(graphics, bitmap, x, y); 
}
