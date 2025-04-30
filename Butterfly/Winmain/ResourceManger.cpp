#include "ResourceManger.h"

ResourceManger::ResourceManger(HINSTANCE hInstance) : hInst(hInstance)
{
}

ResourceManger::~ResourceManger()
{
	delete hInst; 
	DeleteObject(bitmap); 
}

void ResourceManger::Initialize()
{
	imageResource = new ImageResource();
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); 
	bitmap = imageResource->GetBitmap(); 
	width = bitmap->GetWidth(); 
	height = bitmap->GetHeight(); 

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
